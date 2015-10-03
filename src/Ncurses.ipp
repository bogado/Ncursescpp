/*****
 * Copyright Benoit Vey (2015)
 *
 * benoit.vey@etu.upmc.fr
 *
 * This software is a library whose purpose is to provide a RAII-conform
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

#ifndef NCURSESCPP_NCURSES_IPP_
#define NCURSESCPP_NCURSES_IPP_

#include <algorithm>
#include <cassert>

#include "errors.hpp"

namespace nccpp
{

// Input options

/**
 * \brief Change cbreak mode.
 * 
 * \param on If true, call cbreak. Else, call nocbreak.
 * \return The result of the operation.
 */
inline int Ncurses::cbreak(bool on)
{
	return on ? ::cbreak() : nocbreak();
}

/**
 * \brief Change echo mode.
 * 
 * \param on If true, call echo. Else, call noecho.
 * \return The result of the operation.
 */
inline int Ncurses::echo(bool on)
{
	return on ? ::echo() : noecho();
}

/**
 * \brief Call halfdelay.
 * 
 * \param delay Value to pass on to halfdelay.
 * \return The result of the operation.
 */
inline int Ncurses::halfdelay(int delay)
{
	return ::halfdelay(delay);
}

/**
 * \brief Call intrflush.
 * 
 * \param on Value to pass on to intrflush.
 * \return The result of the operation.
 */
inline int Ncurses::intrflush(bool on)
{
	return ::intrflush(win_, on);
}

/**
 * \brief Call meta.
 * 
 * \param on Value to pass on to meta.
 * \return The result of the operation.
 */
inline int Ncurses::meta(bool on)
{
	return ::meta(win_, on);
}

/**
 * \brief Change raw mode.
 * 
 * \param on If true, call raw. Else, call noraw.
 * \return The result of the operation.
 */
inline int Ncurses::raw(bool on)
{
	return on ? ::raw() : noraw();
}

/**
 * \brief Change qiflush mode.
 * 
 * \param on If true, call qiflush. Else, call noquiflush.
 */
inline void Ncurses::qiflush(bool on)
{
	on ? ::qiflush() : noqiflush();
}

/**
 * \brief Call typeahead.
 * 
 * \param fd Value to pass on to typeahead.
 * \return The result of the operation.
 */
inline int Ncurses::typeahead(int fd)
{
	return ::typeahead(fd);
}

// Output options

/**
 * \brief Call clearok.
 * 
 * \param on Value to pass on to clearok.
 * \param use_cs If true, call clearok with *curscr* as argument.
 * \return The result of the operation.
 */
inline int Ncurses::clearok(bool on, bool use_cs)
{
	return::clearok(use_cs ? curscr : win_, on);
}

/**
 * \brief Call idlok.
 * 
 * \param on Value to pass on to idlok.
 * \return The result of the operation.
 */
inline int Ncurses::idlok(bool on)
{
	return ::idlok(win_, on);
}

/**
 * \brief Call idcok.
 * 
 * \param on Value to pass on to idcok.
 */
inline void Ncurses::idcok(bool on)
{
	::idcok(win_, on);
}

/**
 * \brief Call immedok.
 * 
 * \param on Value to pass on to immedok.
 */
inline void Ncurses::immedok(bool on)
{
	::immedok(win_, on);
}

/**
 * \brief Call leaveok.
 * 
 * \param on Value to pass on to leaveok.
 */
inline int Ncurses::leaveok(bool on)
{
	return ::leaveok(win_, on);
}

/**
 * \brief Call scrollok.
 * 
 * \param on Value to pass on to scrollok.
 * \return The result of the operation.
 */
inline int Ncurses::scrollok(bool on)
{
	return ::scrollok(win_, on);
}

/**
 * \brief Change nl mode.
 * 
 * \param on If true, call nl. Else, call nonl.
 * \return The result of the operation.
 */
inline int Ncurses::nl(bool on)
{
	return on ? ::nl() : nonl();
}

// Input functions

/**
 * \brief Call ungetch.
 * 
 * \param ch Value to pass on to ungetch.
 * \return The result of the operation.
 */
inline int Ncurses::ungetch(int ch)
{
	return ::ungetch(ch);
}

/**
 * \brief Call has_key.
 * 
 * \param ch Value to pass on to has_key.
 * \return The result of the operation.
 */
inline int Ncurses::has_key(int ch)
{
	return ::has_key(ch);
}

// Misc

/**
 * \brief Call doupdate.
 * 
 * \return The result of the operation.
 */
inline int Ncurses::doupdate()
{
	return ::doupdate();
}

/**
 * \brief Get the height of the terminal.
 * 
 * \return The number of lines of the terminal.
 */
inline int Ncurses::line_count()
{
	return LINES;
}

/**
 * \brief Get the width of the terminal.
 * 
 * \return The number of columns of the terminal.
 */
inline int Ncurses::column_count()
{
	return COLS;
}

// Window

inline WINDOW* Ncurses::newwin_(int nlines, int ncols, int begin_y, int begin_x, Window::Key /*dummy*/)
{
	return newwin(nlines, ncols, begin_y, begin_x);
}

// Color

/**
 * \brief Start ncurses color mode.
 * 
 * \exception errors::ColorInit Thrown when colors can't be initialized.
 */
inline void Ncurses::start_color()
{
	if (colors_initialized)
		return;
	if (::start_color() == ERR)
		throw errors::ColorInit{};
	colors_initialized = true;
}

/**
 * \brief Call use_default_colors.
 * 
 * \return The result of the operation.
 */
inline int Ncurses::use_default_colors()
{
	start_color();
	return ::use_default_colors();
}

/**
 * \brief Get a pair number from a Color.
 * 
 * \param color The color to get.
 * \exception errors::TooMuchColors Thrown if no more color pairs can be registered.
 * \return The pair number associated with the color.
 */
inline short Ncurses::color_to_pair_number(Color const& color)
{
	auto it = std::find_if(std::begin(registered_colors_), std::end(registered_colors_),
	                       [color](Color const& elem){return color == elem;});
	if (it != std::end(registered_colors_))
		return static_cast<short>(it - std::begin(registered_colors_) + 1);

	start_color();
	// Ensure push_back will not throw
	registered_colors_.reserve(registered_colors_.size() + 1);
	auto res = init_pair(static_cast<short>(registered_colors_.size() + 1),
	                     color.foreground, color.background);
	if (res == ERR)
		throw errors::TooMuchColors{color};
	registered_colors_.push_back(color);
	return static_cast<short>(registered_colors_.size());
}

/**
 * \brief Get an attribute character from a Color.
 * 
 * \param color The color to get.
 * \exception errors::TooMuchColors Thrown if no more color pairs can be registered.
 * \return The attribute associated with the color.
 */
inline attr_t Ncurses::color_to_attr(Color const& color)
{
	return static_cast<attr_t>(COLOR_PAIR(color_to_pair_number(color)));
}

/**
 * \brief Get a Color from a pair number.
 * 
 * \param pair_n The pair number.
 * \pre *pair_n* is a valid pair number.
 * \return The color associated with the pair.
 */
inline Color Ncurses::pair_number_to_color(short pair_n)
{
	assert(static_cast<std::size_t>(pair_n) <= registered_colors_.size() && "No such color");
	return registered_colors_[static_cast<std::size_t>(pair_n - 1)];
}

/**
 * \brief Get a Color from an attribute.
 * 
 * \param a The attribute.
 * \pre The color pair associated with *a* is a valid color attribute.
 * \return The color associated with the attribute.
 */
inline Color Ncurses::attr_to_color(attr_t a)
{
	return pair_number_to_color(static_cast<short>(PAIR_NUMBER(static_cast<int>(a))));
}

/**
 * \brief Call init_color.
 * 
 * \param color,r,g,b Values to pass on to init_color.
 */
inline int Ncurses::init_color(short color, short r, short g, short b)
{
	start_color();
	return ::init_color(color, r, g, b);
}

} // namespace nccpp

#endif // Header guard