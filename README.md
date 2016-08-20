# extrautils

Extra utilities for POSIX systems

This is an in-development collection of additional utilities that may be useful on your average POSIX system.
The utilities are written in C99 and have no external dependencies.

## utilities

* `timestamp`: Prepends a timestamp to each line passed to `stdin`.  Useful for things like `tail /var/log/foo.log | timestamp`.
