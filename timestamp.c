/*
 * Copyright (c) 2016 William Pitcock
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int
main(const int argc, const char *const argv[])
{
	char timebuf[256];
	const char *timefmt = "%Y-%m-%d %H:%M:%S %z";
	bool timestamp_needed = true;
	char ch = '\0';

	if (argc > 1)
		timefmt = argv[1];

	while ((ch = fgetc(stdin)) != EOF)
	{
		if (timestamp_needed)
		{
			time_t ts = time(NULL);

			strftime(timebuf, sizeof timebuf, timefmt, localtime(&ts));
			printf("%s ", timebuf);

			timestamp_needed = false;
		}

		if (fputc(ch, stdout) == EOF)
		{
			perror("fputc");
			return EXIT_FAILURE;
		}

		if (ch == '\n')
			timestamp_needed = true;
	}

	return EXIT_SUCCESS;
}
