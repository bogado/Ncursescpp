/*****
 * Copyright Benoit Vey (2015)
 *
 * benoit.vey@etu.upmc.fr
 *
 * This software is a libray whose purpose is to provide a RAII-conform
 * interface over the ncurses library.
 *
 * This software is governed by the CeCILL-B license under French law and
 * abiding by the rules of distribution of free software.  You can  use, 
 * modify and/ or redistribute the software under the terms of the CeCILL-B
 * license as circulated by CEA, CNRS and INRIA at the following URL
 * "http://www.cecill.info". 
 *
 * As a counterpart to the access to the source code and  rights to copy,
 * modify and redistribute granted by the license, users are provided only
 * with a limited warranty  and the software's author,  the holder of the
 * economic rights,  and the successive licensors  have only  limited
 * liability. 
 *
 * In this respect, the user's attention is drawn to the risks associated
 * with loading,  using,  modifying and/or developing or reproducing the
 * software by the user in light of its specific status of free software,
 * that may mean  that it is complicated to manipulate,  and  that  also
 * therefore means  that it is reserved for developers  and  experienced
 * professionals having in-depth computer knowledge. Users are therefore
 * encouraged to load and test the software's suitability as regards their
 * requirements in conditions enabling the security of their systems and/or 
 * data to be ensured and,  more generally, to use and operate it in the 
 * same conditions as regards security. 
 *
 * The fact that you are presently reading this means that you have had
 * knowledge of the CeCILL-B license and that you accept its terms.
 *****/

#include "Window.hpp"

#include <cassert>

#include <ncurses.h>

namespace nccpp
{

/**
 * \fn int Window::border(chtype ls, chtype rs, chtype ts, chtype bs, chtype tl, chtype tr, chtype bl, chtype br)
 * \brief Call wborder for this window.
 * 
 * \param ls,rs,ts,bs,tl,tr,bl,br Values to pass on to wborder.
 * \pre The Window manages a ncurses window.
 * \return The result of the operation.
 */
int (Window::border)(chtype ls, chtype rs, chtype ts, chtype bs,
                     chtype tl, chtype tr, chtype bl, chtype br)
{
	assert(win_ && "Window doesn't manage any object");
	return wborder(win_, ls, rs, ts, bs, tl, tr, bl, br);
}

/**
 * \fn int Window::box(chtype vch, chtype hch)
 * \brief Call wbox for this window.
 * 
 * \param vch,hch Values to pass on to wbox.
 * \pre The Window manages a ncurses window.
 * \return The result of the operation.
 */
int (Window::box)(chtype vch, chtype hch)
{
	assert(win_ && "Window doesn't manage any object");
	return ::box(win_, vch, hch);
}

/**
 * \fn int Window::hline(chtype ch, int n)
 * \brief Call whline for this window.
 * 
 * \param ch,n Values to pass on to whline.
 * \pre The Window manages a ncurses window.
 * \return The result of the operation.
 */
int (Window::hline)(chtype ch, int n)
{
	assert(win_ && "Window doesn't manage any object");
	return whline(win_, ch, n);
}

/**
 * \fn int Window::vline(chtype ch, int n)
 * \brief Call wvline for this window.
 * 
 * \param ch,n Values to pass on to wvline.
 * \pre The Window manages a ncurses window.
 * \return The result of the operation.
 */
int (Window::vline)(chtype ch, int n)
{
	assert(win_ && "Window doesn't manage any object");
	return wvline(win_, ch, n);
}

/**
 * \fn int Window::mvhline(int y, int x, chtype ch, int n)
 * \brief Call mvwhline for this window.
 * 
 * \param y,x,ch,n Values to pass on to mvwhline.
 * \pre The Window manages a ncurses window.
 * \return The result of the operation.
 */
int (Window::mvhline)(int y, int x, chtype ch, int n)
{
	assert(win_ && "Window doesn't manage any object");
	return move(y, x) == ERR ? ERR : (this->hline)(ch, n);
}

/**
 * \fn int Window::mvvline(int y, int x, chtype ch, int n)
 * \brief Call mvwvline for this window.
 * 
 * \param y,x,ch,n Values to pass on to mvwvline.
 * \pre The Window manages a ncurses window.
 * \return The result of the operation.
 */
int (Window::mvvline)(int y, int x, chtype ch, int n)
{
	assert(win_ && "Window doesn't manage any object");
	return move(y, x) == ERR ? ERR : (this->vline)(ch, n);
}

/**
 * \fn void Window::bkgdset(int ch)
 * \brief Call wbkgdset for this window.
 * 
 * \param ch Value to pass on to wbkgdset.
 * \pre The Window manages a ncurses window.
 */
void (Window::bkgdset)(int ch)
{
	assert(win_ && "Window doesn't manage any object");
	wbkgdset(win_, static_cast<chtype>(ch));
}

/**
 * \fn int Window::bkgd(int ch)
 * \brief Call wbkgd for this window.
 * 
 * \param ch Values to pass on to wbkgd.
 * \pre The Window manages a ncurses window.
 * \return The result of the operation.
 */
int (Window::bkgd)(int ch)
{
	assert(win_ && "Window doesn't manage any object");
	return wbkgd(win_, static_cast<chtype>(ch));
}

/**
 * \fn chtype Window::getbkgd()
 * \brief Call getbkgd for this window.
 * 
 * \pre The Window manages a ncurses window.
 * \return The background character.
 */
chtype (Window::getbkgd)()
{
	assert(win_ && "Window doesn't manage any object");
	return (::getbkgd)(win_);
}

} // namespace nccpp