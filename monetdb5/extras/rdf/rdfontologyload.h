/*
 * The contents of this file are subject to the MonetDB Public License
 * Version 1.1 (the "License"); you may not use this file except in
 * compliance with the License. You may obtain a copy of the License at
 * http://www.monetdb.org/Legal/MonetDBLicense
 *
 * Software distributed under the License is distributed on an "AS IS"
 * basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See the
 * License for the specific language governing rights and limitations
 * under the License.
 *
 * The Original Code is the MonetDB Database System.
 *
 * The Initial Developer of the Original Code is CWI.
 * Portions created by CWI are Copyright (C) 1997-July 2008 CWI.
 * Copyright August 2008-2013 MonetDB B.V.
 * All Rights Reserved.
 */

#ifndef _RDFONTOLOGY_H_
#define _RDFONTOLOGY_H_

typedef struct OntClass {
	oid 	ocId; 		/*class Id */
	oid	subclassof;
	oid* 	lstProp;
	int	numProp;
	int 	numAllocation;
} OntClass; 

typedef struct OntClassset{
	OntClass* items;
	int numClassadded;
	int numAllocation;
} OntClassset; 

rdf_export str
RDFOntologyParser(int *ret, str *location, str *schema);

rdf_export str
RDFloadsqlontologies(int *ret, bat *auri, bat *aattr, bat *muri, bat *msuper);

/*
rdf_export str
RDFOntologyRead(int *ret, bat *ontcBatid, bat *ontaBatid, OntClassset* ontclassset);  */


#endif /* _RDFSCHEMA_H_ */
