/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uolle <uolle>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 21:59:23 by uolle             #+#    #+#             */
/*   Updated: 2024/08/02 22:19:35 by uolle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/charger.h"

/**
 * @brief Check if the charger is plugged
 * @return 1 if the charger is plugged, 0 otherwise, -1 in case of error
 */
static int	is_charger_plugged(void)
{
	FILE	*file;
	char	status[2];

	file = fopen(CHARGER_PATH, "r");
	if (!file)
	{
		perror("Failed to open charger status file");
		return (-1);
	}
	fgets(status, 2, file);
	fclose(file);
	return (strcmp(status, "1") == 0);
}

/**
 * @brief Main function
 * @return 0 on success, 1 on failure
 */
int	main(void)
{
	int	prev_state;
	int	current_state;

	prev_state = is_charger_plugged();
	if (prev_state == -1)
		return (EXIT_FAILURE);
	while (1)
	{
		current_state = is_charger_plugged();
		if (current_state != prev_state)
		{
			if (current_state == 1)
				system(SOUND_COMMAND);
			prev_state = current_state;
		}
	}
	return (EXIT_SUCCESS);
}
