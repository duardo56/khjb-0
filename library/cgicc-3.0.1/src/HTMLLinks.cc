/*
 *  $Id: HTMLLinks.cc,v 1.6 1999/05/25 19:16:47 sbooth Exp $
 *
 *  Copyright (C) 1996, 1997, 1998, 1999 Stephen F. Booth
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifdef __GNUG__
#pragma implementation
#endif

#include "HTMLLinks.hh"

// ============================================================
// Statics
// ============================================================
bool CGICCNS a::sState = false;

// ============================================================
// Class a
// ============================================================
CGICCNS a::a()
  : HTMLBooleanElement("", 0, 0, false)
{}

CGICCNS a::a(const STDNS string& text) 
  : HTMLBooleanElement(text, 0, 0, true)
{}

CGICCNS a::a(const HTMLAttributeList& attributes)
  : HTMLBooleanElement("", &attributes, 0, false)
{}

CGICCNS a::a(const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", 0, &embed, false)
{}

CGICCNS a::a(const STDNS string& text, 
	    const HTMLAttributeList& attributes) 
  : HTMLBooleanElement(text, &attributes, 0, true)
{}

CGICCNS a::a(const HTMLAttributeList& attributes, 
	    const HTMLSimpleElement& embed)
  : HTMLBooleanElement("", &attributes, &embed, false)
{}

CGICCNS a::~a()
{}

// ============================================================
// Class link
// ============================================================
CGICCNS link::link() 
{}

CGICCNS link::link(const HTMLAttributeList& attributes)
  : HTMLElement(&attributes)
{}

CGICCNS link::~link()
{}

// ============================================================
// Class base
// ============================================================
CGICCNS base::base() 
{}

CGICCNS base::base(const HTMLAttributeList& attributes)
  : HTMLElement(&attributes)
{}

CGICCNS base::~base()
{}
