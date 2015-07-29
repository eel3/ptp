ptp (print-thread-priority)
===========================

Command line tool to show magic numbers of thread priority.

License
-------

zlib License.

Target environments
-------------------

Windows, Linux, Mac OS X.

Set up
------

1. Compile ptp.c. Use make and Makefile.
2. Put ptp in a directory registered in PATH.

| toolset              | Makefile           |
|:---------------------|:-------------------|
| Linux                | unix/Makefile      |
| Mac OS X (Xcode)     | unix/Makefile\_mac |
| Microsoft Visual C++ | win/Makefile       |

Usage
-----

Simply execute `ptp`. ptp has no option.

Example
-------

Example on Windows 7:

    > ptp
    THREAD_PRIORITY_IDLE	-15
    THREAD_PRIORITY_LOWEST	-2
    THREAD_PRIORITY_BELOW_NORMAL	-1
    THREAD_PRIORITY_NORMAL	0
    THREAD_PRIORITY_ABOVE_NORMAL	1
    THREAD_PRIORITY_HIGHEST	2
    THREAD_PRIORITY_TIME_CRITICAL	15

Example on Linux:

    $ ptp
    SCHED_FIFO	1	99
    SCHED_OTHER	0	0
    SCHED_RR	1	99
