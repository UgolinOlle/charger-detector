/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charger.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uolle <uolle>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 21:58:57 by uolle             #+#    #+#             */
/*   Updated: 2024/08/02 23:09:25 by uolle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARGER_H
# define CHARGER_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define CHARGER_PATH "/sys/class/power_supply/macsmc-ac/online"
# define SOUND_COMMAND "aplay ~/Music/charger-detector/click.wav"

#endif
