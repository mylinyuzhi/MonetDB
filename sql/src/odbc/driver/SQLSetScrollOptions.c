/*
 * The contents of this file are subject to the MonetDB Public
 * License Version 1.0 (the "License"); you may not use this file
 * except in compliance with the License. You may obtain a copy of
 * the License at 
 * http://monetdb.cwi.nl/Legal/MonetDBLicense-1.0.html
 * 
 * Software distributed under the License is distributed on an "AS
 * IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
 * implied. See the License for the specific language governing
 * rights and limitations under the License.
 * 
 * The Original Code is the Monet Database System.
 * 
 * The Initial Developer of the Original Code is CWI.
 * Portions created by CWI are Copyright (C) 1997-2002 CWI.  
 * All Rights Reserved.
 * 
 * Contributor(s):
 * 		Martin Kersten <Martin.Kersten@cwi.nl>
 * 		Peter Boncz <Peter.Boncz@cwi.nl>
 * 		Niels Nes <Niels.Nes@cwi.nl>
 * 		Stefan Manegold  <Stefan.Manegold@cwi.nl>
 */

/********************************************************************
 * SQLSetScrollOptions()
 * CLI Compliance: deprecated in ODBC 3.0 (replaced by SQLSetStmtAttr()
 * Provided here for old (pre ODBC 3.0) applications and driver managers.
 *
 * Author: Martin van Dinther
 * Date  : 30 aug 2002
 *
 ********************************************************************/

#include "ODBCGlobal.h"
#include "ODBCStmt.h"

SQLRETURN SQLSetScrollOptions(
	SQLHSTMT	hStmt,
	SQLUSMALLINT	fConcurrency,
	SQLINTEGER	crowKeyset,
	SQLUSMALLINT	crowRowset )
{
	if (! isValidStmt(hStmt))
		return SQL_INVALID_HANDLE;

	/* TODO: implement the mapping to multiple SQLSetStmtAttr() calls */
	/* See ODBC 3.5 SDK Help file for details */

	/* for now simply return "not supported" error */
	addStmtError(hStmt, "IM001", NULL, 0);
	return SQL_ERROR;
}
