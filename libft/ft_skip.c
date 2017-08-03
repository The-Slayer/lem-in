/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 14:59:01 by hstander          #+#    #+#             */
/*   Updated: 2017/08/01 13:48:03 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_skip(char const *s, int *i, char c)
{
	while (s[*i] == c)
		*i += 1;
}

void	ft_skip2(char const *s, int *i, char c)
{
	while (s[*i] == c || s[*i] == '\t')
		*i += 1;
}
