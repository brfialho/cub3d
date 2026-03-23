/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 07:23:13 by brfialho          #+#    #+#             */
/*   Updated: 2026/03/22 08:00:57 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include "main.h"

# define RED "\001\033[31m\002"
# define GREEN "\001\033[32m\002"
# define BOLD "\001\033[1m\002"
# define RESET "\001\033[0m\002"
# define YELLOW "\001\033[33m\002"

# define TEST BOLD "%d. " RESET "Testing with " YELLOW BOLD "\"%s\"\n"
# define TEST_SUCCESS GREEN BOLD "=== SUCCESS ✅ ===\n\n" RESET
# define TEST_FAIL RED BOLD "=== FAILURE ❌ ===\n\n" RESET

#endif