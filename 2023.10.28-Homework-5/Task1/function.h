#pragma once
#ifndef FUNCTION_H
#define FUNCTION_H

void PrintMenu();
void print_array(int*& a, int len);
void add_element(int*& a, int& len, int b);
void delete_element(int*& a, int& len, int& b);
void sort_massive(int*& a, int& len);
void reverse_massive(int*& a, int& len);
void change_max_min(int*& a, int& len);
void delete_dublicates(int*& a, int& len);
void add_random_elements(int*& a, int& len, int count);
#endif
