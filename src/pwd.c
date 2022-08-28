/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:59:39 by adaifi            #+#    #+#             */
/*   Updated: 2022/08/18 09:20:22 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../mini.h"

void	pwd_env(void)
{
	char	cwd[1024];

	if (getcwd(cwd, sizeof(cwd)))
		ft_putendl_fd(cwd, 1);
	else
	{
		var.exit_status = 1;
		ft_putendl_fd("Unable to get working directory", 2);
	}
}
