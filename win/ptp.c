/* ********************************************************************** */
/**
 * @brief   Command line tool to show magic numbers of thread priority.
 * @author  eel3
 * @date    2014/10/27
 *
 * @par OS:
 *   - Windows 7 Ultimate 64bit SP1
 */
/* ********************************************************************** */


#include <stdio.h>
#include <stdlib.h>

#include <windows.h>
#include <tchar.h>


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
_tmain(void)
{
	static const struct {
		int priority;
		LPCTSTR name;
	} THREAD_PRIORITY[] = {
#define MAPSYM(sym) { sym, _T(#sym), }
		MAPSYM(THREAD_PRIORITY_IDLE),
		MAPSYM(THREAD_PRIORITY_LOWEST),
		MAPSYM(THREAD_PRIORITY_BELOW_NORMAL),
		MAPSYM(THREAD_PRIORITY_NORMAL),
		MAPSYM(THREAD_PRIORITY_ABOVE_NORMAL),
		MAPSYM(THREAD_PRIORITY_HIGHEST),
		MAPSYM(THREAD_PRIORITY_TIME_CRITICAL),
#undef MAPSYM
	};
	size_t i;

	for (i = 0; i < NELEMS(THREAD_PRIORITY); i++) {
		(void) _tprintf(_T("%s\t%d\n"), THREAD_PRIORITY[i].name, THREAD_PRIORITY[i].priority);
	}

	return EXIT_SUCCESS;
}
