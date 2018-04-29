/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_gamemode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 18:34:10 by susivagn          #+#    #+#             */
/*   Updated: 2018/04/29 18:35:33 by susivagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_sdl.h"

int		memory_update(t_sdl *sdlinfo)
{
	printf("---- IN MEMORY UPDATE ----\n");
	if (GAMEMODE == 1)
	{
		get_txt_color(sdlinfo);
		if (PLAYER > 0)
		MEM_ZONE = TTF_RenderText_Shaded(sdlinfo->police, "01", sdlinfo->txt_color, sdlinfo->bg_color);
		else
		MEM_ZONE = TTF_RenderText_Solid(sdlinfo->police, "00", sdlinfo->grey);
	}
	else
	{
		get_block_color(sdlinfo);
		if (PLAYER > 0)
		MEM_ZONE = TTF_RenderText_Shaded(sdlinfo->police, "  ", sdlinfo->txt_color, sdlinfo->bg_color);
		else
		MEM_ZONE = TTF_RenderText_Shaded(sdlinfo->police, "  ", sdlinfo->txt_color, sdlinfo->grey);
	}
	printf("TFF EXIT\n");
	if (MEM_ZONE == NULL)
	{
		printf("ERROR: Memory TTF_Render\n");
		return (-1);
	}
	return (1);
}

void	get_block_color(t_sdl *sdlinfo)
{
	printf("++++ In Block Color ++++\n");
	if (sdlinfo->pc == 0)
	{
		if (PLAYER == 1)
			sdlinfo->bg_color = sdlinfo->pc_red;
		else if (PLAYER == 2)
			sdlinfo->bg_color = sdlinfo->pc_blue;
		else if (PLAYER == 3)
			sdlinfo->bg_color = sdlinfo->pc_green;
		else if (PLAYER == 4)
			sdlinfo->bg_color = sdlinfo->pc_yellow;
	}
	else
	{
		if (PLAYER == 1)
			sdlinfo->bg_color = sdlinfo->red;
		else if (PLAYER == 2)
			sdlinfo->bg_color = sdlinfo->blue;
		else if (PLAYER == 3)
			sdlinfo->bg_color = sdlinfo->green;
		if (PLAYER == 4)
			sdlinfo->bg_color = sdlinfo->yellow;
	}
	printf("++++ END Block Color ++++\n");
}

void	get_txt_color(t_sdl *sdlinfo)
{
	printf("++++ In Get Texte Color ++++\n");
	if (sdlinfo->pc == 0)
	{
		sdlinfo->bg_color = sdlinfo->black;
		if (PLAYER == 1)
			sdlinfo->txt_color = sdlinfo->red;
		else if (PLAYER == 2)
			sdlinfo->txt_color = sdlinfo->blue;
		else if (PLAYER == 3)
			sdlinfo->txt_color = sdlinfo->green;
		else if (PLAYER == 4)
			sdlinfo->txt_color = sdlinfo->yellow;
	}
	else
	{
		sdlinfo->txt_color = sdlinfo->black;
		if (PLAYER == 1)
			sdlinfo->bg_color = sdlinfo->red;
		else if (PLAYER == 2)
			sdlinfo->bg_color = sdlinfo->blue;
		else if (PLAYER == 3)
			sdlinfo->bg_color = sdlinfo->green;
		if (PLAYER == 4)
			sdlinfo->bg_color = sdlinfo->yellow;
	}
	printf("++++ END Texte Color ++++\n");
}
