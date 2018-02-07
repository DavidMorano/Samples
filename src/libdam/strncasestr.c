/* strncasestr */

/* find a substring within a larger string (case insensitive) */


/* revision history:

	= 1998-03-23, David A�D� Morano
	This subroutine was originally written.

*/

/* Copyright � 1998 David A�D� Morano.  All rights reserved. */

/*******************************************************************************

	This subroutine determines if the parameter string (argument 's2') is
	or is not a substring specified by the first two arguments.  This
	subroutine either returns a pointer to the the begining of the found
	substring or NULL if not found.  The string comparisons are case
	insensitive.

	Synopsis:

	char *strncasestr(sp,sl,s2)
	const char	sp[] ;
	int		sl ;
	const char	s2[] ;

	Arguments:

	sp		(s1) string to be examined
	sl		(s1) length of string to be examined
	s2		null terminated substring to search for

	Returns:

	-		pointer to found substring
	NULL		substring was not found
	sp		pointer to 's1' if 'ss' is zero length


*******************************************************************************/


#include	<envstandards.h>	/* MUST be first to configure */

#include	<sys/types.h>
#include	<string.h>

#include	<char.h>
#include	<localmisc.h>


/* local defines */


/* external subroutines */

extern int	nleadcasestr(const char *,const char *,int) ;


/* exported subroutines */


char *strncasestr(cchar *sp,int sl,cchar *s2)
{
	const int	s2len = strlen(s2) ;
	char		*rp = (char *) sp ;

	if (s2len > 0) {
	    if (sl < 0) sl = strlen(sp) ;
	    if (s2len <= sl) {
		const int	s2lead = CHAR_TOLC(s2[0]) ;
		int		m ;
	        int		i ;
		int		f = FALSE ;
	        for (i = 0 ; i <= (sl-s2len) ; i += 1) {
	            if (CHAR_TOLC(sp[i]) == s2lead) {
	                m = nleadcasestr((sp+i),s2,s2len) ;
	                f = (m == s2len) ;
			if (f) break ;
	            } /* end if */
	        } /* end for */
	        rp = (char *) ((f) ? (sp+i) : NULL) ;
	    } else {
	        rp = NULL ;
	    }
	} /* end if (positive) */

	return rp ;
}
/* end subroutine (strncasestr) */


