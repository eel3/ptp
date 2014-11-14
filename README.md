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

All you have to do is compile ptp.c. Use make and Makefile.

| toolset              | Makefile           |
|:---------------------|:-------------------|
| Linux                | unix/Makefile      |
| Mac OS X (Xcode)     | unix/Makefile\_mac |
| Microsoft Visual C++ | win/Makefile       |

Usage
-----

See \`Example'. midiport has no option.

Example
-------

    > rem Example on Windows 7
    
    > ptp
    THREAD_PRIORITY_IDLE	-15
    THREAD_PRIORITY_LOWEST	-2
    THREAD_PRIORITY_BELOW_NORMAL	-1
    THREAD_PRIORITY_NORMAL	0
    THREAD_PRIORITY_ABOVE_NORMAL	1
    THREAD_PRIORITY_HIGHEST	2
    THREAD_PRIORITY_TIME_CRITICAL	15
    
    > _

    $ # Example on Linux
    $ ptp
    SCHED_FIFO	1	99
    SCHED_OTHER	0	0
    SCHED_RR	1	99
