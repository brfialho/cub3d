/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 07:28:07 by brfialho          #+#    #+#             */
/*   Updated: 2026/03/22 08:52:17 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "tests.h"

t_bool	split_cmp(char **split, char **expected)
{
	int	i = -1;

	if (!split)
		return (FAILURE);
	while (expected[++i])
		if (!split[i] || ft_strcmp(split[i], expected[i]))
			return (FAILURE);
	return (SUCCESS);
}

t_bool	path_cmp(char **split, char **expected)
{
	int	i = -1;

	while (++i < TEXTURE_COUNT)
		if (ft_strcmp(split[i], expected[i]))
		{
			ft_printf("AQUI\n");
			return (FAILURE);
		}
	return (SUCCESS);
}

t_bool	tester_parser_cmp(t_game *game, t_game *expected)
{
	if (split_cmp((char **)game->map.tab, (char **)expected->map.tab)
		|| path_cmp((char **)game->path, (char **)expected->path))
		return (FAILURE);
	return (SUCCESS);
}

t_bool	test_valid__basic(t_game *game, char *file)
{
	t_bool	status;
	t_game	expected;

	status = parsing(game, file);
	if (status == FAILURE)
		return (FAILURE);
	char *expected_map[] =          {"        1111111111111111111111111",
									 "        1000000000110000000000001",
									 "        1011000001110000000000001",
									 "        1001000000000000000000001",
									 "111111111011000001110000000000001",
									 "100000000011000001110111111111111",
									 "11110111111111011100000010001    ",
									 "11110111111111011101010010001    ",
									 "11000000110101011100000010001    ",
									 "10000000000000001100000010001    ",
									 "10000000000000001101010010001    ",
									 "11000001110101011111011110N0111  ",
									 "11110111 1110101 101111010001    ",
									 "11111111 1111111 111111111111    ",
									 NULL};
	expected.map.tab = (void **)expected_map;
	expected.path[NORTH] = "./path_to_the_north_texture";
	expected.path[SOUTH] = "./path_to_the_south_texture";
	expected.path[EAST] = "./path_to_the_east_texture";
	expected.path[WEST] = "./path_to_the_west_texture";
	if (tester_parser_cmp(game, &expected))
		return (FAILURE);
	return (SUCCESS);
}

t_bool	test_invalid(t_game *game, char *file)
{
	return (!parsing(game, file));
}

int main(void)
{
	t_game	game;
	ft_bzero(&game, sizeof(t_game));
	char	*tests[100] = {NULL};
	t_bool	(*test_functions[100])(t_game *, char *);

	tests[0] = "tests/tester_parser/invalid_maps/1_missing_element_texture.cub";
	tests[1] = "tests/tester_parser/invalid_maps/2_empty.cub";
	tests[2] = "tests/tester_parser/invalid_maps/3_only_empty_lines.cub";
	tests[3] = "tests/tester_parser/invalid_maps/4_no_.cub_extension.txt";
	tests[4] = "tests/tester_parser/invalid_maps/5_extra_element.cub";
	tests[5] = "tests/tester_parser/invalid_maps/6_extra_word_in_element_texture.cub";
	tests[6] = "tests/tester_parser/invalid_maps/7_missing_word_in_texture.cub";
	tests[7] = "tests/tester_parser/invalid_maps/8_missing_element_color.cub";
	tests[8] = "tests/tester_parser/invalid_maps/9_letter_in_element_color";
	tests[9] = "tests/tester_parser/invalid_maps/10_missing_element_color.cub";
	tests[10] = "tests/tester_parser/invalid_maps/11_no_map.cub";
	tests[11] = "tests/tester_parser/invalid_maps/12_invalid_char_in_map.cub";
	tests[12] = "tests/tester_parser/invalid_maps/13_map_too_small_vertically.cub";
	tests[13] = "tests/tester_parser/invalid_maps/14_map_too_small_horizontally.cub";
	tests[14] = "tests/tester_parser/invalid_maps/15_open_map.cub";
	tests[15] = "tests/tester_parser/invalid_maps/16_open_island.cub";

	// tests[0] = "tests/tester_parser/valid_maps/1_basic.cub";

	test_functions[0] = test_invalid;
	test_functions[1] = test_invalid;
	test_functions[2] = test_invalid;
	test_functions[3] = test_invalid;
	test_functions[4] = test_invalid;
	test_functions[5] = test_invalid;
	test_functions[6] = test_invalid;
	test_functions[7] = test_invalid;
	test_functions[8] = test_invalid;
	test_functions[9] = test_invalid;
	test_functions[10] = test_invalid;
	test_functions[11] = test_invalid;
	test_functions[12] = test_invalid;
	test_functions[13] = test_invalid;
	test_functions[14] = test_invalid;
	test_functions[15] = test_invalid;
	// test_functions[0] = test_valid__basic;

	int	test_len = 0;
	while (tests[test_len])
		test_len++;
	int i = -1;
	int	j;
	while (++i < test_len)
	{
		ft_printf(TEST, i + 1, tests[i]);
		if (test_functions[i](&game, tests[i]))
			ft_printf(TEST_FAIL);
		else
			ft_printf(TEST_SUCCESS);

		j = -1;
		while (++j < TEXTURE_COUNT)
			if (game.path[j])
				free(game.path[j]);
		if (game.map.tab)
			ft_tab_free_content(&game.map);
		ft_bzero(&game, sizeof(t_game));
	}
}
