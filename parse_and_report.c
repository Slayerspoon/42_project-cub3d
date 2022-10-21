/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_report.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:33:43 by aionescu          #+#    #+#             */
/*   Updated: 2022/10/21 17:30:52 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	report_error_batch_one(int error_code)
{
	if (error_code == 1)
		printf("Error:\nIncorrect file extension.\n");
	else if (error_code == 2)
		printf("Error:\nFile could not be opened.\n");
	else if (error_code == 3)
		printf("Error:\nMissing or incorrect element N.\n");
	else if (error_code == 4)
		printf("Error:\nMissing or incorrect element S.\n");
	else if (error_code == 5)
		printf("Error:\nMissing or incorrect element E.\n");
	else if (error_code == 6)
		printf("Error:\nMissing or incorrect element W.\n");
	else if (error_code == 7)
		printf("Error:\nMissing or incorrect element F.\n");
	else if (error_code == 8)
		printf("Error:\nMissing or incorrect element C.\n");
	else if (error_code == 9)
		printf("Error:\nNo map layout information.\n");
}

void	report_error_batch_two(int error_code)
{
	if (error_code == 10)
		printf("Error:\nUnallowed beginning of line.\n");
	else if (error_code == 11)
		printf("Error:\nUnallowed beginning of line in or after \
		the map layout information lines.\n");
	else if (error_code == 12)
		printf("Error:\nNon-empty line after map layout information lines.\n");
	else if (error_code == 13)
		printf("Error:\nErroneous definition of NSEWFC information element.\n");
}

void	report_error_batch_three(int error_code)
{
	if (error_code == 21)
		printf("Error:\nMap layout not completely walled on the left side.\n");
	else if (error_code == 22)
		printf("Error:\nMap layout not completely walled on the right side.\n");
	else if (error_code == 23)
		printf("Error:\nMap layout not completely walled on the upper side.\n");
	else if (error_code == 24)
		printf("Error:\nMap layout not completely walled on the lower side.\n");
	else if (error_code == 25)
		printf("Error:\nMap layout contains unrendered squares \
		that are not walled off from the explorable squares.\n");
}

int	parse_and_report(int argc, char **argv, t_gamedata *gamedata)
{
	int	error_code;

	if (argc != 2)
	{
		printf("Error:\nInvalid number of arguments provided.\n");
		return (100);
	}
	error_code = file_structure_check(argv[1]);
	if (error_code == 0)
		error_code = process_gamedata(argv[1], gamedata);
	if (error_code == 0)
		error_code = layout_logic_check(gamedata);
	if (error_code != 0)
	{
		if (1 <= error_code && error_code <= 9)
			report_error_batch_one(error_code);
		if (10 <= error_code && error_code <= 13)
			report_error_batch_two(error_code);
		if (21 <= error_code && error_code <= 25)
			report_error_batch_three(error_code);
		return (error_code);
	}
	return (0);
}
