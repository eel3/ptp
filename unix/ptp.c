/* ********************************************************************** */
/**
 * @brief   Command line tool to show magic numbers of thread priority.
 * @author  eel3
 * @date    2014/10/27
 *
 * @par OS:
 *   - CentOS 5.11 64bit
 *   - Mac OS X 10.9.4
 */
/* ********************************************************************** */


#ifndef _POSIX_PRIORITY_SCHEDULING
#	define _POSIX_PRIORITY_SCHEDULING
#endif /* ndef _POSIX_PRIORITY_SCHEDULING */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include <libgen.h>
#include <sched.h>
#include <unistd.h>


/* ---------------------------------------------------------------------- */
/* Function-like macro */
/* ---------------------------------------------------------------------- */

/* ====================================================================== */
/**
 * @brief  Return number of elements in array.
 *
 * @param[in] ary  array
 *
 * @return  number of elements in array.
 */
/* ====================================================================== */
#define NELEMS(ary) (sizeof(ary) / sizeof((ary)[0]))


/* ---------------------------------------------------------------------- */
/* Function */
/* ---------------------------------------------------------------------- */

/* ********************************************************************** */
/**
 * @brief  Main routine.
 *
 * @return  EXIT_SUCCESS
 */
/* ********************************************************************** */
int
main(int argc, char *argv[])
{
	static const struct {
		int policy;
		const char *name;
	} POLICIES[] = {
#define MAPSYM(sym) { sym, #sym, }
		MAPSYM(SCHED_FIFO),
		MAPSYM(SCHED_OTHER),
		MAPSYM(SCHED_RR),
#undef MAPSYM
	};
	size_t i;

	(void) argc;

	for (i = 0; i < NELEMS(POLICIES); i++) {
		int priority_min, priority_max;

		errno = 0;
		priority_min = sched_get_priority_min(POLICIES[i].policy);
		priority_max = sched_get_priority_max(POLICIES[i].policy);
		if ((priority_min < 0) || (priority_max < 0)) {
			perror(basename(argv[0]));
			continue;
		}
		(void) printf("%s\t%d\t%d\n", POLICIES[i].name, priority_min, priority_max);
	}

	return EXIT_SUCCESS;
}
