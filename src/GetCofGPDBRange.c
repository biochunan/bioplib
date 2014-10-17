/************************************************************************/
/**

   \file       GetCofGPDBRange.c
   
   \version    V1.2
   \date       07.07.14
   \brief      Find CofG of a PDB linked list
   
   \copyright  (c) UCL / Dr. Andrew C. R. Martin 1992-4
   \author     Dr. Andrew C. R. Martin
   \par
               Institute of Structural & Molecular Biology,
               University College London,
               Gower Street,
               London.
               WC1E 6BT.
   \par
               andrew@bioinf.org.uk
               andrew.martin@ucl.ac.uk
               
**************************************************************************

   This code is NOT IN THE PUBLIC DOMAIN, but it may be copied
   according to the conditions laid out in the accompanying file
   COPYING.DOC.

   The code may be modified as required, but any modifications must be
   documented so that the person responsible can be identified.

   The code may not be sold commercially or included as part of a 
   commercial product except as described in the file COPYING.DOC.

**************************************************************************

   Description:
   ============


**************************************************************************

   Usage:
   ======

**************************************************************************

   Revision History:
   =================
-  V1.0  01.10.92 Original
-  V1.1  03.10.94 Added GetCofGPDBRange(), FindCofGPDBSCRange() and 
                  fixed NULL coord search in GetCofGPDB()
-  V1.2  07.07.14 Use bl prefix for functions By: CTP

*************************************************************************/
/* Doxygen
   -------
   #GROUP    Handling PDB Data
   #SUBGROUP Calculations
   #FUNCTION  blGetCofGPDBRange()
   Find CofG of a range in a PDB linked list, ignoring NULL coordinates
*/
/************************************************************************/
/* Includes
*/
#include <math.h>

#include "pdb.h"
#include "macros.h"
#include "MathType.h"

/************************************************************************/
/* Defines
*/

/************************************************************************/
/* Prototypes
*/

/************************************************************************/
/* Variables global to this file only
*/


/************************************************************************/
/*>void blGetCofGPDBRange(PDB *start, PDB *stop, VEC3F *cg)
   --------------------------------------------------------
*//**

   \param[in]     *start     Start of region of interest in PDB list
   \param[in]     *stop      Beginning of next residue
   \param[out]    *cg        Centre of geometry of specified region

   Find CofG of a range in a PDB linked list, ignoring NULL coordinates
   (specified as all coords==9999.000)

-  03.10.94 Original    By: ACRM
-  07.07.14 Use bl prefix for functions By: CTP
*/
void blGetCofGPDBRange(PDB *start, PDB *stop, VEC3F *cg)
{
   int natom;
   PDB *p;

   cg->x = 0.0;   
   cg->y = 0.0;   
   cg->z = 0.0;   
   natom = 0;

   for(p=start; p!=NULL && p!=stop; NEXT(p))
   {
      if(p->x < 9999.0 || p->y < 9999.0 || p->z < 9999.0)
      {
         cg->x += p->x;
         cg->y += p->y;
         cg->z += p->z;
         natom++;
      }
   }

   cg->x /= natom;
   cg->y /= natom;
   cg->z /= natom;
}

