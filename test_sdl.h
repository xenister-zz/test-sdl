/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sdl.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 17:10:59 by susivagn          #+#    #+#             */
/*   Updated: 2018/04/20 18:17:02 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TEST_SDL_H_
# define _TEST_SDL_H_

# include <stdlib.h>
# include <stdio.h>
# include <SDL/SDL.h>
# include <SDL_image.h>

# define WINDOW_W 800
# define WINDOW_H 800
# define BPP 32

int            start_screen(SDL_Surface *screen);
SDL_Surface		*init_sdl(SDL_Surface *screen);

#endif