/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daarriba <daarriba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:29:56 by daarriba          #+#    #+#             */
/*   Updated: 2020/02/10 13:58:35 by daarriba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c);
void	ft_print_alphabet(void);
void	ft_print_reverse_alphabet(void);
void	ft_print_numbers(void);
void	ft_is_negative(int n);
void	ft_print_comb(void);
void	ft_two_digits(int nb);
void	ft_print_comb2(void);
void	ft_putnbr(int n);

int		main(void)
{
    ft_putchar('a');
    printf("\n");
    ft_print_alphabet();
    printf("\n");
    ft_print_reverse_alphabet();
    printf("\n");
    ft_print_numbers();
    printf("\n");
    ft_is_negative(42);
    printf("\n");
    ft_print_comb();
    printf("\n");
    ft_print_comb2();
    printf("\n");
    ft_putnbr(-42);
}
