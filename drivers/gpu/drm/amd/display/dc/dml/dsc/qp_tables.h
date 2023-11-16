
/*
 * Copyright 2017 Advanced Micro Devices, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Authors: AMD
 *
 */


static const qp_table   qp_table_422_10bpc_min = {
	{   6, { 0, 4, 5, 6, 6, 6, 6, 7, 7, 8, 9, 9, 9, 12, 16} },
	{ 6.5, { 0, 4, 5, 6, 6, 6, 6, 7, 7, 8, 9, 9, 9, 12, 16} },
	{   7, { 0, 4, 5, 6, 6, 6, 6, 7, 7, 7, 9, 9, 9, 11, 15} },
	{ 7.5, { 0, 2, 4, 6, 6, 6, 6, 7, 7, 7, 8, 9, 9, 11, 15} },
	{   8, { 0, 2, 3, 5, 5, 6, 6, 7, 7, 7, 8, 8, 9, 11, 14} },
	{ 8.5, { 0, 2, 3, 4, 5, 5, 5, 6, 6, 7, 8, 8, 9, 11, 14} },
	{   9, { 0, 2, 3, 4, 5, 5, 5, 6, 6, 7, 8, 8, 9, 11, 13} },
	{ 9.5, { 0, 2, 3, 4, 4, 5, 5, 6, 6, 7, 8, 8, 9, 11, 13} },
	{  10, { 0, 2, 2, 3, 4, 5, 5, 6, 6, 7, 8, 8, 9, 11, 12} },
	{10.5, { 0, 2, 2, 3, 4, 4, 5, 6, 6, 7, 8, 8, 9, 11, 12} },
	{  11, { 0, 2, 2, 3, 4, 4, 5, 6, 6, 7, 8, 8, 9, 10, 11} },
	{11.5, { 0, 2, 2, 3, 4, 4, 5, 5, 6, 7, 7, 8, 8, 10, 11} },
	{  12, { 0, 2, 2, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 9, 10} },
	{12.5, { 0, 1, 2, 2, 4, 4, 4, 5, 5, 6, 6, 7, 8, 9, 10} },
	{  13, { 0, 1, 2, 2, 4, 4, 4, 5, 5, 6, 6, 6, 8, 8, 9} },
	{13.5, { 0, 1, 2, 2, 3, 4, 4, 4, 5, 6, 6, 6, 7, 8, 9} },
	{  14, { 0, 1, 2, 2, 3, 4, 4, 4, 4, 5, 5, 6, 7, 7, 8} },
	{14.5, { 0, 1, 1, 2, 3, 3, 4, 4, 4, 5, 5, 6, 6, 7, 8} },
	{  15, { 0, 1, 1, 2, 2, 3, 3, 4, 4, 4, 5, 6, 6, 6, 8} },
	{15.5, { 0, 0, 1, 1, 2, 3, 3, 3, 4, 4, 5, 5, 5, 6, 7} },
	{  16, { 0, 0, 1, 1, 2, 3, 3, 3, 4, 4, 5, 5, 5, 5, 7} },
	{16.5, { 0, 0, 0, 1, 1, 2, 2, 3, 3, 3, 3, 4, 4, 5, 6} },
	{  17, { 0, 0, 0, 0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 6} },
	{17.5, { 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 3, 3, 4, 5} },
	{  18, { 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 5} },
	{18.5, { 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 5} },
	{  19, { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 4} },
	{19.5, { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 4} },
	{  20, { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 3} }
};


static const qp_table   qp_table_444_8bpc_max = {
	{   6, { 4, 6, 8, 8, 9, 9, 9, 10, 11, 12, 12, 12, 12, 13, 15} },
	{ 6.5, { 4, 6, 7, 8, 8, 8, 9, 10, 11, 11, 12, 12, 12, 13, 15} },
	{   7, { 4, 5, 7, 7, 8, 8, 8, 9, 10, 11, 11, 12, 12, 13, 14} },
	{ 7.5, { 4, 5, 6, 7, 7, 8, 8, 9, 10, 10, 11, 11, 12, 13, 14} },
	{   8, { 4, 4, 5, 6, 7, 7, 7, 8, 9, 10, 10, 11, 11, 12, 13} },
	{ 8.5, { 4, 4, 5, 6, 7, 7, 7, 8, 9, 10, 10, 11, 11, 12, 13} },
	{   9, { 3, 4, 5, 6, 7, 7, 7, 8, 9, 9, 10, 10, 11, 11, 13} },
	{ 9.5, { 3, 4, 5, 6, 7, 7, 7, 8, 9, 9, 10, 10, 11, 11, 13} },
	{  10, { 3, 4, 5, 6, 7, 7, 7, 8, 9, 9, 10, 10, 11, 11, 12} },
	{10.5, { 3, 4, 5, 6, 7, 7, 7, 8, 9, 9, 10, 10, 10, 11, 12} },
	{  11, { 2, 4, 5, 6, 7, 7, 7, 8, 8, 9, 9, 9, 10, 10, 11} },
	{11.5, { 2, 4, 5, 6, 7, 7, 7, 8, 8, 9, 9, 9, 9, 10, 11} },
	{  12, { 2, 3, 4, 5, 6, 6, 7, 8, 8, 9, 9, 9, 9, 10, 11} },
	{12.5, { 2, 3, 4, 5, 6, 6, 6, 7, 7, 8, 8, 9, 9, 10, 11} },
	{  13, { 1, 3, 4, 5, 5, 6, 6, 7, 7, 8, 8, 8, 8, 9, 10} },
	{13.5, { 1, 2, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 10} },
	{  14, { 1, 2, 2, 3, 4, 4, 4, 5, 6, 6, 7, 8, 8, 8, 10} },
	{14.5, { 0, 1, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 9} },
	{  15, { 0, 1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 7, 7, 8, 9} },
	{15.5, { 0, 1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 7, 7, 8, 9} },
	{  16, { 0, 1, 1, 2, 2, 3, 3, 4, 5, 5, 5, 6, 6, 7, 8} },
	{16.5, { 0, 1, 1, 2, 2, 3, 3, 4, 5, 5, 5, 6, 6, 7, 8} },
	{  17, { 0, 1, 1, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 6, 8} },
	{17.5, { 0, 1, 1, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 6, 8} },
	{  18, { 0, 1, 1, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 6, 7} },
	{18.5, { 0, 1, 1, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 6, 7} },
	{  19, { 0, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 4, 4, 5, 6} },
	{19.5, { 0, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 4, 4, 5, 6} },
	{  20, { 0, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 4, 6} },
	{20.5, { 0, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 4, 6} },
	{  21, { 0, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 4, 5} },
	{21.5, { 0, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 4, 5} },
	{  22, { 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 5} },
	{22.5, { 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 4} },
	{  23, { 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 4} },
	{23.5, { 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 4} },
	{  24, { 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 2, 4} }
};


static const qp_table   qp_table_420_12bpc_max = {
	{   4, {11, 12, 13, 14, 15, 15, 15, 16, 17, 18, 18, 19, 19, 21, 22} },
	{ 4.5, {10, 11, 12, 13, 14, 15, 15, 16, 17, 18, 18, 19, 19, 20, 21} },
	{   5, { 9, 11, 12, 13, 14, 15, 15, 16, 17, 17, 18, 18, 19, 20, 21} },
	{ 5.5, { 8, 10, 11, 12, 13, 14, 15, 16, 16, 17, 17, 18, 18, 19, 20} },
	{   6, { 6, 9, 11, 12, 13, 14, 15, 16, 16, 17, 17, 17, 17, 18, 19} },
	{ 6.5, { 6, 8, 10, 11, 11, 13, 14, 15, 15, 16, 16, 17, 17, 18, 19} },
	{   7, { 5, 7, 9, 10, 10, 12, 13, 14, 14, 15, 16, 16, 17, 17, 18} },
	{ 7.5, { 5, 7, 8, 9, 9, 11, 12, 13, 14, 14, 15, 15, 16, 16, 17} },
	{   8, { 4, 6, 7, 8, 8, 10, 11, 12, 13, 13, 14, 15, 15, 16, 17} },
	{ 8.5, { 3, 6, 6, 7, 7, 10, 11, 12, 13, 13, 14, 14, 15, 15, 16} },
	{   9, { 3, 5, 6, 7, 7, 10, 11, 12, 12, 13, 13, 14, 14, 14, 15} },
	{ 9.5, { 2, 5, 6, 6, 7, 9, 10, 11, 12, 12, 13, 13, 13, 14, 15} },
	{  10, { 2, 4, 5, 6, 7, 8, 9, 10, 11, 12, 12, 13, 13, 13, 15} },
	{10.5, { 2, 3, 5, 5, 6, 7, 8, 9, 11, 11, 12, 12, 12, 12, 14} },
	{  11, { 1, 3, 4, 5, 6, 6, 7, 9, 10, 11, 11, 11, 12, 12, 13} },
	{11.5, { 1, 2, 3, 4, 5, 6, 6, 8, 9, 10, 10, 11, 11, 11, 13} },
	{  12, { 1, 1, 3, 3, 4, 5, 6, 7, 8, 9, 9, 10, 10, 10, 12} },
	{12.5, { 1, 1, 2, 3, 4, 5, 6, 7, 8, 8, 9, 9, 9, 10, 11} },
	{  13, { 1, 1, 1, 2, 4, 4, 6, 6, 7, 8, 8, 9, 9, 9, 11} },
	{13.5, { 1, 1, 1, 2, 3, 4, 5, 5, 6, 7, 8, 8, 8, 9, 11} },
	{  14, { 1, 1, 1, 2, 3, 4, 4, 5, 6, 6, 7, 8, 8, 8, 10} },
	{14.5, { 0, 1, 1, 1, 2, 3, 4, 4, 5, 5, 6, 7, 7, 7, 9} },
	{  15, { 0, 1, 1, 1, 1, 2, 3, 3, 5, 5, 5, 6, 6, 7, 9} },
	{15.5, { 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 8} },
	{  16, { 0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 7} },
	{16.5, { 0, 0, 0, 0, 0, 1, 2, 2, 2, 3, 3, 4, 4, 5, 7} },
	{  17, { 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 3, 3, 3, 4, 6} },
	{17.5, { 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 3, 3, 4, 6} },
	{  18, { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 5} }
};


static const qp_table   qp_table_444_10bpc_min = {
	{   6, { 0, 4, 7, 7, 9, 9, 9, 9, 9, 10, 10, 10, 10, 12, 18} },
	{ 6.5, { 0, 4, 6, 7, 8, 8, 9, 9, 9, 9, 10, 10, 10, 12, 18} },
	{   7, { 0, 4, 6, 6, 8, 8, 8, 8, 8, 9, 9, 10, 10, 12, 17} },
	{ 7.5, { 0, 4, 6, 6, 7, 8, 8, 8, 8, 8, 9, 9, 10, 12, 17} },
	{   8, { 0, 4, 5, 5, 7, 7, 7, 7, 7, 8, 9, 9, 9, 12, 16} },
	{ 8.5, { 0, 4, 5, 5, 7, 7, 7, 7, 7, 8, 9, 9, 9, 12, 16} },
	{   9, { 0, 4, 5, 5, 7, 7, 7, 7, 7, 7, 9, 9, 9, 12, 16} },
	{ 9.5, { 0, 4, 5, 5, 7, 7, 7, 7, 7, 7, 9, 9, 9, 12, 16} },
	{  10, { 0, 4, 5, 5, 7, 7, 7, 7, 7, 7, 9, 9, 9, 12, 15} },
	{10.5, { 0, 4, 5, 5, 7, 7, 7, 7, 7, 7, 9, 9, 9, 12, 15} },
	{  11, { 0, 3, 5, 5, 7, 7, 7, 7, 7, 7, 9, 9, 9, 11, 14} },
	{11.5, { 0, 3, 5, 5, 7, 7, 7, 7, 7, 7, 9, 9, 9, 11, 14} },
	{  12, { 0, 2, 4, 4, 6, 6, 7, 7, 7, 7, 9, 9, 9, 11, 14} },
	{12.5, { 0, 2, 4, 4, 6, 6, 7, 7, 7, 7, 8, 9, 9, 11, 14} },
	{  13, { 0, 2, 4, 4, 5, 6, 7, 7, 7, 7, 8, 9, 9, 11, 13} },
	{13.5, { 0, 2, 3, 4, 5, 6, 6, 7, 7, 7, 8, 9, 9, 11, 13} },
	{  14, { 0, 2, 3, 4, 5, 5, 6, 6, 7, 7, 8, 9, 9, 11, 13} },
	{14.5, { 0, 2, 3, 4, 5, 5, 6, 6, 6, 7, 7, 8, 9, 11, 12} },
	{  15, { 0, 2, 3, 4, 4, 5, 5, 6, 6, 6, 7, 8, 9, 11, 12} },
	{15.5, { 0, 2, 3, 4, 4, 5, 5, 6, 6, 6, 7, 8, 9, 11, 12} },
	{  16, { 0, 2, 3, 4, 4, 5, 5, 6, 6, 6, 7, 8, 8, 10, 11} },
	{16.5, { 0, 1, 2, 3, 4, 5, 5, 6, 6, 6, 7, 8, 8, 10, 11} },
	{  17, { 0, 1, 2, 3, 3, 4, 5, 5, 5, 6, 6, 7, 8, 9, 11} },
	{17.5, { 0, 1, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 9, 11} },
	{  18, { 0, 1, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 9, 10} },
	{18.5, { 0, 1, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 9, 10} },
	{  19, { 0, 1, 1, 2, 3, 3, 3, 4, 5, 6, 6, 7, 7, 8, 9} },
	{19.5, { 0, 1, 1, 2, 3, 3, 3, 4, 5, 6, 6, 7, 7, 8, 9} },
	{  20, { 0, 1, 1, 2, 2, 3, 3, 4, 5, 5, 5, 6, 6, 7, 9} },
	{20.5, { 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 9} },
	{  21, { 0, 1, 1, 2, 2, 3, 3, 4, 4, 4, 5, 6, 6, 7, 9} },
	{21.5, { 0, 1, 1, 2, 2, 2, 3, 4, 4, 4, 5, 6, 6, 7, 8} },
	{  22, { 0, 0, 1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 5, 6, 8} },
	{22.5, { 0, 0, 1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 5, 6, 7} },
	{  23, { 0, 0, 1, 2, 2, 2, 3, 3, 3, 3, 5, 5, 5, 5, 7} },
	{23.5, { 0, 0, 0, 2, 2, 2, 3, 3, 3, 3, 5, 5, 5, 5, 7} },
	{  24, { 0, 0, 0, 1, 1, 2, 3, 3, 3, 3, 4, 4, 4, 5, 7} },
	{24.5, { 0, 0, 0, 1, 1, 2, 2, 3, 3, 3, 4, 4, 4, 5, 7} },
	{  25, { 0, 0, 0, 0, 1, 2, 2, 2, 3, 3, 4, 4, 4, 4, 6} },
	{25.5, { 0, 0, 0, 0, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 6} },
	{  26, { 0, 0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 3, 3, 3, 5} },
	{26.5, { 0, 0, 0, 0, 0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 5} },
	{  27, { 0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 5} },
	{27.5, { 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 3, 3, 3, 5} },
	{  28, { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 4} },
	{28.5, { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 4} },
	{  29, { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 3} },
	{29.5, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 3} },
	{  30, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 3} }
};


static const qp_table   qp_table_420_8bpc_max = {
	{   4, { 4, 4, 5, 6, 7, 7, 7, 8, 9, 10, 10, 11, 11, 13, 14} },
	{ 4.5, { 4, 4, 5, 6, 7, 7, 7, 8, 9, 10, 10, 11, 11, 12, 13} },
	{   5, { 3, 4, 5, 6, 7, 7, 7, 8, 9, 9, 10, 10, 11, 12, 13} },
	{ 5.5, { 3, 4, 5, 6, 7, 7, 7, 8, 8, 9, 9, 10, 10, 11, 12} },
	{   6, { 2, 4, 5, 6, 7, 7, 7, 8, 8, 9, 9, 9, 9, 10, 11} },
	{ 6.5, { 2, 3, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 11} },
	{   7, { 1, 2, 3, 4, 4, 5, 5, 6, 6, 7, 8, 8, 9, 9, 10} },
	{ 7.5, { 1, 2, 2, 3, 3, 4, 4, 5, 6, 6, 7, 7, 8, 8, 9} },
	{   8, { 0, 1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 7, 7, 8, 9} },
	{ 8.5, { 0, 1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6, 7, 7, 8} },
	{   9, { 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 6, 7} },
	{ 9.5, { 0, 1, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 5, 6, 7} },
	{  10, { 0, 0, 1, 1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 5, 6} },
	{10.5, { 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 4, 4, 4, 4, 6} },
	{  11, { 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 5} },
	{11.5, { 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 3, 3, 4, 5} },
	{  12, { 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 3, 4} }
};


static const qp_table   qp_table_444_8bpc_min = {
	{   6, { 0, 1, 3, 3, 5, 5, 5, 5, 5, 6, 6, 6, 6, 9, 14} },
	{ 6.5, { 0, 1, 2, 3, 4, 4, 5, 5, 5, 5, 6, 6, 6, 9, 14} },
	{   7, { 0, 0, 2, 2, 4, 4, 4, 4, 4, 5, 5, 6, 6, 9, 13} },
	{ 7.5, { 0, 0, 2, 2, 3, 4, 4, 4, 4, 4, 5, 5, 6, 9, 13} },
	{   8, { 0, 0, 1, 1, 3, 3, 3, 3, 3, 4, 5, 5, 5, 8, 12} },
	{ 8.5, { 0, 0, 1, 1, 3, 3, 3, 3, 3, 4, 5, 5, 5, 8, 12} },
	{   9, { 0, 0, 1, 1, 3, 3, 3, 3, 3, 3, 5, 5, 5, 7, 12} },
	{ 9.5, { 0, 0, 1, 1, 3, 3, 3, 3, 3, 3, 5, 5, 5, 7, 12} },
	{  10, { 0, 0, 1, 1, 3, 3, 3, 3, 3, 3, 5, 5, 5, 7, 11} },
	{10.5, { 0, 0, 1, 1, 3, 3, 3, 3, 3, 3, 5, 5, 5, 7, 11} },
	{  11, { 0, 0, 1, 1, 3, 3, 3, 3, 3, 3, 5, 5, 5, 7, 10} },
	{11.5, { 0, 0, 1, 1, 3, 3, 3, 3, 3, 3, 5, 5, 5, 7, 10} },
	{  12, { 0, 0, 1, 1, 3, 3, 3, 3, 3, 3, 5, 5, 5, 7, 10} },
	{12.5, { 0, 0, 1, 1, 3, 3, 3, 3, 3, 3, 4, 5, 5, 7, 10} },
	{  13, { 0, 0, 1, 1, 2, 3, 3, 3, 3, 3, 4, 5, 5, 7, 9} },
	{13.5, { 0, 0, 0, 1, 1, 2, 2, 2, 2, 3, 4, 5, 5, 7, 9} },
	{  14, { 0, 0, 0, 0, 1, 1, 2, 2, 2, 3, 4, 5, 5, 7, 9} },
	{14.5, { 0, 0, 0, 0, 1, 1, 2, 2, 2, 3, 4, 4, 5, 7, 8} },
	{  15, { 0, 0, 0, 0, 1, 1, 1, 2, 2, 3, 4, 4, 5, 7, 8} },
	{15.5, { 0, 0, 0, 0, 1, 1, 1, 2, 2, 3, 4, 4, 5, 7, 8} },
	{  16, { 0, 0, 0, 0, 1, 1, 1, 2, 2, 3, 4, 4, 5, 6, 7} },
	{16.5, { 0, 0, 0, 0, 1, 1, 1, 2, 2, 3, 4, 4, 5, 6, 7} },
	{  17, { 0, 0, 0, 0, 1, 1, 1, 2, 2, 3, 3, 4, 4, 5, 7} },
	{17.5, { 0, 0, 0, 0, 1, 1, 1, 2, 2, 3, 3, 4, 4, 5, 7} },
	{  18, { 0, 0, 0, 0, 1, 1, 1, 2, 2, 3, 3, 4, 4, 5, 6} },
	{18.5, { 0, 0, 0, 0, 1, 1, 1, 2, 2, 3, 3, 4, 4, 5, 6} },
	{  19, { 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4, 5} },
	{19.5, { 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4, 5} },
	{  20, { 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 3, 5} },
	{20.5, { 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 3, 5} },
	{  21, { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 3, 4} },
	{21.5, { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 3, 4} },
	{  22, { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 4} },
	{22.5, { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 3} },
	{  23, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 3} },
	{23.5, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 3} },
	{  24, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3} }
};


static const qp_table   qp_table_444_12bpc_min = {
	{   6, { 0, 5, 11, 11, 13, 13, 13, 13, 13, 14, 14, 14, 14, 17, 22} },
	{ 6.5, { 0, 5, 10, 11, 12, 12, 13, 13, 13, 13, 14, 14, 14, 17, 22} },
	{   7, { 0, 5, 10, 10, 12, 12, 12, 12, 12, 13, 13, 14, 14, 17, 21} },
	{ 7.5, { 0, 5, 9, 10, 11, 12, 12, 12, 12, 12, 13, 13, 14, 17, 21} },
	{   8, { 0, 4, 8, 9, 11, 11, 11, 11, 11, 12, 13, 13, 13, 16, 20} },
	{ 8.5, { 0, 4, 8, 9, 11, 11, 11, 11, 11, 12, 13, 13, 13, 16, 20} },
	{   9, { 0, 4, 8, 9, 11, 11, 11, 11, 11, 11, 13, 13, 13, 15, 20} },
	{ 9.5, { 0, 4, 8, 9, 11, 11, 11, 11, 11, 11, 13, 13, 13, 15, 20} },
	{  10, { 0, 4, 8, 9, 11, 11, 11, 11, 11, 11, 13, 13, 13, 15, 19} },
	{10.5, { 0, 4, 8, 9, 11, 11, 11, 11, 11, 11, 13, 13, 13, 15, 19} },
	{  11, { 0, 4, 8, 9, 11, 11, 11, 11, 11, 11, 13, 13, 13, 15, 18} },
	{11.5, { 0, 4, 8, 9, 11, 11, 11, 11, 11, 11, 13, 13, 13, 15, 18} },
	{  12, { 0, 4, 7, 8, 10, 11, 11, 11, 11, 11, 13, 13, 13, 15, 18} },
	{12.5, { 0, 4, 7, 8, 10, 11, 11, 11, 11, 11, 13, 13, 13, 15, 18} },
	{  13, { 0, 4, 7, 8, 9, 11, 11, 11, 11, 11, 13, 13, 13, 15, 17} },
	{13.5, { 0, 3, 6, 7, 9, 10, 10, 11, 11, 11, 12, 13, 13, 15, 17} },
	{  14, { 0, 3, 5, 6, 9, 9, 9, 10, 11, 11, 12, 13, 13, 15, 17} },
	{14.5, { 0, 2, 5, 6, 8, 9, 9, 10, 11, 11, 12, 13, 13, 15, 16} },
	{  15, { 0, 2, 4, 6, 7, 8, 9, 10, 11, 11, 12, 13, 13, 15, 16} },
	{15.5, { 0, 2, 4, 6, 7, 8, 9, 10, 11, 11, 12, 13, 13, 15, 16} },
	{  16, { 0, 2, 4, 6, 7, 8, 9, 10, 11, 11, 11, 12, 12, 14, 15} },
	{16.5, { 0, 2, 3, 5, 7, 8, 9, 10, 11, 11, 11, 12, 12, 14, 15} },
	{  17, { 0, 2, 3, 5, 5, 6, 9, 9, 10, 10, 11, 11, 12, 13, 15} },
	{17.5, { 0, 2, 3, 5, 5, 6, 8, 9, 10, 10, 11, 11, 12, 13, 15} },
	{  18, { 0, 2, 3, 5, 5, 6, 8, 9, 10, 10, 11, 11, 12, 13, 14} },
	{18.5, { 0, 2, 3, 5, 5, 6, 8, 9, 10, 10, 11, 11, 12, 13, 14} },
	{  19, { 0, 1, 2, 4, 5, 5, 7, 8, 9, 9, 10, 11, 11, 12, 13} },
	{19.5, { 0, 1, 2, 4, 5, 5, 7, 8, 9, 9, 10, 11, 11, 12, 13} },
	{  20, { 0, 1, 2, 3, 4, 5, 7, 8, 8, 8, 9, 10, 10, 11, 13} },
	{20.5, { 0, 1, 2, 3, 4, 5, 6, 7, 7, 8, 9, 10, 10, 11, 13} },
	{  21, { 0, 1, 2, 3, 4, 5, 5, 7, 7, 8, 9, 10, 10, 11, 13} },
	{21.5, { 0, 1, 2, 3, 3, 4, 5, 7, 7, 8, 9, 10, 10, 11, 12} },
	{  22, { 0, 0, 1, 3, 3, 4, 5, 6, 7, 8, 9, 9, 9, 10, 12} },
	{22.5, { 0, 0, 1, 3, 3, 4, 5, 6, 7, 8, 9, 9, 9, 10, 11} },
	{  23, { 0, 0, 1, 3, 3, 4, 5, 6, 6, 7, 9, 9, 9, 9, 11} },
	{23.5, { 0, 0, 1, 3, 3, 4, 5, 6, 6, 7, 9, 9, 9, 9, 11} },
	{  24, { 0, 0, 1, 2, 3, 4, 5, 6, 6, 7, 8, 8, 8, 9, 11} },
	{24.5, { 0, 0, 1, 2, 3, 4, 4, 6, 6, 7, 8, 8, 8, 9, 11} },
	{  25, { 0, 0, 1, 2, 3, 4, 4, 5, 6, 7, 8, 8, 8, 8, 10} },
	{25.5, { 0, 0, 1, 2, 3, 4, 4, 5, 6, 6, 7, 8, 8, 8, 10} },
	{  26, { 0, 0, 1, 2, 2, 3, 4, 5, 5, 6, 7, 7, 7, 7, 9} },
	{26.5, { 0, 0, 1, 2, 2, 3, 4, 5, 5, 5, 7, 7, 7, 7, 9} },
	{  27, { 0, 0, 1, 2, 2, 3, 4, 4, 5, 5, 6, 7, 7, 7, 9} },
	{27.5, { 0, 0, 1, 1, 2, 2, 4, 4, 4, 5, 6, 7, 7, 7, 9} },
	{  28, { 0, 0, 0, 1, 1, 2, 3, 4, 4, 4, 6, 6, 6, 7, 9} },
	{28.5, { 0, 0, 0, 1, 1, 2, 3, 3, 4, 4, 5, 6, 6, 6, 8} },
	{  29, { 0, 0, 0, 1, 1, 2, 3, 3, 4, 4, 5, 5, 6, 6, 8} },
	{29.5, { 0, 0, 0, 1, 1, 1, 2, 2, 3, 4, 5, 5, 6, 6, 7} },
	{  30, { 0, 0, 0, 1, 1, 1, 2, 2, 3, 3, 5, 5, 5, 5, 7} },
	{30.5, { 0, 0, 0, 0, 0, 1, 1, 2, 2, 3, 4, 4, 4, 5, 7} },
	{  31, { 0, 0, 0, 0, 0, 1, 1, 2, 2, 3, 4, 4, 4, 5, 7} },
	{31.5, { 0, 0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 7} },
	{  32, { 0, 0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 3, 3, 4, 6} },
	{32.5, { 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 3, 3, 3, 4, 6} },
	{  33, { 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 3, 3, 3, 5} },
	{33.5, { 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 3, 3, 3, 5} },
	{  34, { 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 2, 2, 3, 5} },
	{34.5, { 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 2, 3, 5} },
	{  35, { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 4} },
	{35.5, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 4} },
	{  36, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 3} }
};


static const qp_table   qp_table_420_12bpc_min = {
	{   4, { 0, 4, 9, 10, 11, 11, 11, 11, 11, 11, 13, 13, 13, 15, 21} },
	{ 4.5, { 0, 4, 8, 9, 10, 11, 11, 11, 11, 11, 13, 13, 13, 15, 20} },
	{   5, { 0, 4, 8, 9, 10, 11, 11, 11, 11, 11, 13, 13, 13, 15, 20} },
	{ 5.5, { 0, 4, 7, 8, 10, 11, 11, 11, 11, 11, 13, 13, 13, 15, 19} },
	{   6, { 0, 4, 7, 8, 10, 11, 11, 11, 11, 11, 13, 13, 13, 15, 18} },
	{ 6.5, { 0, 4, 6, 8, 9, 10, 11, 11, 11, 11, 13, 13, 13, 15, 18} },
	{   7, { 0, 3, 5, 7, 9, 10, 10, 11, 11, 11, 13, 13, 13, 15, 17} },
	{ 7.5, { 0, 3, 5, 7, 8, 9, 10, 10, 11, 11, 12, 13, 13, 15, 16} },
	{   8, { 0, 2, 4, 6, 7, 9, 9, 10, 11, 11, 12, 13, 13, 15, 16} },
	{ 8.5, { 0, 2, 4, 6, 6, 9, 9, 10, 11, 11, 12, 12, 13, 14, 15} },
	{   9, { 0, 2, 4, 6, 6, 9, 9, 10, 10, 11, 11, 12, 13, 13, 14} },
	{ 9.5, { 0, 2, 4, 5, 6, 8, 8, 9, 10, 10, 11, 12, 12, 13, 14} },
	{  10, { 0, 2, 3, 5, 6, 7, 8, 8, 9, 10, 10, 12, 12, 12, 14} },
	{10.5, { 0, 2, 3, 4, 5, 6, 7, 8, 9, 9, 10, 11, 11, 11, 13} },
	{  11, { 0, 2, 3, 4, 5, 5, 6, 8, 8, 9, 9, 10, 11, 11, 12} },
	{11.5, { 0, 1, 2, 3, 4, 5, 5, 7, 8, 8, 9, 10, 10, 10, 12} },
	{  12, { 0, 0, 2, 2, 3, 4, 5, 6, 7, 8, 8, 9, 9, 9, 11} },
	{12.5, { 0, 0, 1, 2, 3, 4, 5, 6, 7, 7, 8, 8, 8, 9, 10} },
	{  13, { 0, 0, 0, 1, 3, 3, 5, 5, 6, 7, 7, 8, 8, 8, 10} },
	{13.5, { 0, 0, 0, 1, 2, 3, 4, 4, 5, 6, 7, 7, 7, 8, 10} },
	{  14, { 0, 0, 0, 1, 2, 3, 3, 4, 5, 5, 6, 7, 7, 7, 9} },
	{14.5, { 0, 0, 0, 0, 1, 2, 3, 3, 4, 4, 5, 6, 6, 6, 8} },
	{  15, { 0, 0, 0, 0, 0, 1, 2, 2, 4, 4, 4, 5, 5, 6, 8} },
	{15.5, { 0, 0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 7} },
	{  16, { 0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 6} },
	{16.5, { 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 3, 3, 4, 6} },
	{  17, { 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 5} },
	{17.5, { 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 3, 5} },
	{  18, { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 4} }
};


static const qp_table   qp_table_422_12bpc_min = {
	{   6, { 0, 4, 9, 10, 11, 11, 11, 11, 11, 11, 13, 13, 13, 16, 20} },
	{ 6.5, { 0, 4, 9, 10, 11, 11, 11, 11, 11, 11, 13, 13, 13, 16, 20} },
	{   7, { 0, 4, 9, 10, 11, 11, 11, 11, 11, 11, 13, 13, 13, 15, 19} },
	{ 7.5, { 0, 4, 8, 10, 11, 11, 11, 11, 11, 11, 13, 13, 13, 15, 19} },
	{   8, { 0, 4, 7, 8, 10, 11, 11, 11, 11, 11, 13, 13, 13, 15, 18} },
	{ 8.5, { 0, 3, 6, 8, 9, 10, 10, 11, 11, 11, 12, 13, 13, 15, 18} },
	{   9, { 0, 3, 5, 8, 9, 10, 10, 10, 11, 11, 12, 13, 13, 15, 17} },
	{ 9.5, { 0, 3, 5, 7, 8, 9, 10, 10, 11, 11, 12, 13, 13, 15, 17} },
	{  10, { 0, 2, 4, 6, 7, 9, 9, 10, 11, 11, 12, 13, 13, 15, 16} },
	{10.5, { 0, 2, 4, 6, 7, 8, 9, 10, 11, 11, 12, 13, 13, 15, 16} },
	{  11, { 0, 2, 4, 6, 7, 8, 9, 10, 11, 11, 12, 12, 13, 14, 15} },
	{11.5, { 0, 2, 4, 6, 7, 7, 9, 9, 10, 11, 11, 12, 12, 14, 15} },
	{  12, { 0, 2, 4, 6, 6, 6, 8, 8, 9, 9, 11, 11, 12, 13, 14} },
	{12.5, { 0, 1, 4, 5, 6, 6, 7, 8, 8, 9, 10, 11, 11, 13, 14} },
	{  13, { 0, 1, 3, 4, 5, 5, 7, 8, 8, 9, 10, 10, 11, 12, 13} },
	{13.5, { 0, 1, 3, 3, 4, 5, 7, 7, 8, 8, 10, 10, 10, 12, 13} },
	{  14, { 0, 0, 2, 3, 4, 5, 6, 6, 7, 7, 9, 10, 10, 11, 12} },
	{14.5, { 0, 0, 1, 3, 4, 4, 6, 6, 6, 7, 9, 9, 9, 11, 12} },
	{  15, { 0, 0, 1, 3, 3, 4, 5, 6, 6, 6, 8, 9, 9, 10, 12} },
	{15.5, { 0, 0, 1, 2, 3, 4, 5, 5, 6, 6, 8, 8, 8, 10, 11} },
	{  16, { 0, 0, 1, 2, 3, 4, 5, 5, 6, 6, 8, 8, 8, 9, 11} },
	{16.5, { 0, 0, 0, 2, 2, 3, 4, 5, 5, 5, 6, 7, 7, 9, 10} },
	{  17, { 0, 0, 0, 1, 2, 2, 4, 4, 4, 5, 6, 6, 6, 8, 10} },
	{17.5, { 0, 0, 0, 1, 2, 2, 3, 4, 4, 4, 5, 6, 6, 8, 9} },
	{  18, { 0, 0, 0, 1, 2, 2, 3, 3, 3, 4, 5, 5, 6, 7, 9} },
	{18.5, { 0, 0, 0, 1, 2, 2, 3, 3, 3, 3, 5, 5, 5, 7, 9} },
	{  19, { 0, 0, 0, 1, 2, 2, 2, 3, 3, 3, 4, 4, 5, 6, 8} },
	{19.5, { 0, 0, 0, 1, 1, 1, 2, 3, 3, 3, 4, 4, 4, 6, 8} },
	{  20, { 0, 0, 0, 1, 1, 1, 2, 3, 3, 3, 4, 4, 4, 5, 7} },
	{20.5, { 0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 4, 5, 7} },
	{  21, { 0, 0, 0, 0, 0, 1, 2, 2, 3, 3, 3, 4, 4, 4, 6} },
	{21.5, { 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 3, 3, 3, 4, 6} },
	{  22, { 0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 2, 3, 3, 4, 6} },
	{22.5, { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 5} },
	{  23, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 3, 5} },
	{23.5, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 4} },
	{  24, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 4} }
};


static const qp_table   qp_table_422_12bpc_max = {
	{   6, {12, 12, 13, 14, 15, 15, 15, 16, 17, 18, 18, 19, 19, 20, 21} },
	{ 6.5, {12, 12, 13, 14, 15, 15, 15, 16, 17, 18, 18, 19, 19, 20, 21} },
	{   7, {11, 12, 13, 14, 15, 15, 15, 16, 17, 17, 18, 18, 19, 19, 20} },
	{ 7.5, { 9, 10, 12, 14, 15, 15, 15, 16, 16, 17, 17, 18, 18, 19, 20} },
	{   8, { 6, 9, 10, 12, 14, 15, 15, 16, 16, 17, 17, 17, 17, 18, 19} },
	{ 8.5, { 6, 8, 9, 11, 13, 14, 14, 15, 15, 16, 16, 17, 17, 18, 19} },
	{   9, { 5, 7, 8, 10, 12, 13, 13, 14, 14, 15, 15, 16, 16, 17, 18} },
	{ 9.5, { 5, 7, 7, 9, 10, 12, 12, 13, 14, 14, 15, 15, 16, 17, 18} },
	{  10, { 4, 6, 6, 8, 9, 11, 11, 12, 13, 13, 14, 15, 15, 16, 17} },
	{10.5, { 4, 6, 6, 8, 9, 10, 11, 12, 13, 13, 14, 15, 15, 16, 17} },
	{  11, { 4, 5, 6, 8, 9, 10, 11, 12, 13, 13, 14, 14, 15, 15, 16} },
	{11.5, { 3, 5, 6, 8, 9, 9, 11, 11, 12, 13, 13, 14, 14, 15, 16} },
	{  12, { 3, 5, 6, 8, 8, 8, 10, 10, 11, 11, 13, 13, 14, 14, 15} },
	{12.5, { 3, 4, 6, 7, 8, 8, 9, 10, 10, 11, 12, 13, 13, 14, 15} },
	{  13, { 2, 4, 5, 6, 7, 7, 9, 10, 10, 11, 12, 12, 13, 13, 14} },
	{13.5, { 2, 4, 5, 5, 6, 7, 9, 9, 10, 10, 12, 12, 12, 13, 14} },
	{  14, { 2, 3, 4, 5, 6, 7, 8, 8, 9, 9, 11, 12, 12, 12, 13} },
	{14.5, { 2, 3, 3, 5, 6, 6, 8, 8, 8, 9, 11, 11, 11, 12, 13} },
	{  15, { 2, 3, 3, 5, 5, 6, 7, 8, 8, 8, 10, 11, 11, 11, 13} },
	{15.5, { 2, 2, 3, 4, 5, 6, 7, 7, 8, 8, 10, 10, 10, 11, 12} },
	{  16, { 2, 2, 3, 4, 5, 6, 7, 7, 8, 8, 10, 10, 10, 10, 12} },
	{16.5, { 1, 2, 2, 4, 4, 5, 6, 7, 7, 7, 8, 9, 9, 10, 11} },
	{  17, { 1, 1, 2, 3, 4, 4, 6, 6, 6, 7, 8, 8, 8, 9, 11} },
	{17.5, { 1, 1, 2, 3, 4, 4, 5, 6, 6, 6, 7, 8, 8, 9, 10} },
	{  18, { 1, 1, 1, 2, 3, 3, 5, 5, 5, 6, 7, 7, 8, 8, 10} },
	{18.5, { 1, 1, 1, 2, 3, 3, 5, 5, 5, 5, 7, 7, 7, 8, 10} },
	{  19, { 1, 1, 1, 2, 3, 3, 4, 5, 5, 5, 6, 6, 7, 7, 9} },
	{19.5, { 1, 1, 1, 2, 2, 2, 4, 5, 5, 5, 6, 6, 6, 7, 9} },
	{  20, { 1, 1, 1, 2, 2, 2, 4, 5, 5, 5, 6, 6, 6, 6, 8} },
	{20.5, { 0, 0, 0, 1, 2, 2, 3, 3, 4, 4, 5, 5, 5, 6, 8} },
	{  21, { 0, 0, 0, 1, 1, 2, 3, 3, 4, 4, 4, 5, 5, 5, 7} },
	{21.5, { 0, 0, 0, 0, 1, 1, 2, 3, 3, 3, 4, 4, 4, 5, 7} },
	{  22, { 0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 3, 4, 4, 5, 7} },
	{22.5, { 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 6} },
	{  23, { 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 3, 3, 4, 6} },
	{23.5, { 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 3, 5} },
	{  24, { 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 3, 5} }
};


static const qp_table   qp_table_444_12bpc_max = {
	{   6, {12, 14, 16, 16, 17, 17, 17, 18, 19, 20, 20, 20, 20, 21, 23} },
	{ 6.5, {12, 14, 15, 16, 16, 16, 17, 18, 19, 19, 20, 20, 20, 21, 23} },
	{   7, {12, 13, 15, 15, 16, 16, 16, 17, 18, 19, 19, 20, 20, 21, 22} },
	{ 7.5, {12, 13, 14, 15, 15, 16, 16, 17, 18, 18, 19, 19, 20, 21, 22} },
	{   8, {12, 12, 13, 14, 15, 15, 15, 16, 17, 18, 18, 19, 19, 20, 21} },
	{ 8.5, {12, 12, 13, 14, 15, 15, 15, 16, 17, 18, 18, 19, 19, 20, 21} },
	{   9, {11, 12, 13, 14, 15, 15, 15, 16, 17, 17, 18, 18, 19, 19, 21} },
	{ 9.5, {11, 12, 13, 14, 15, 15, 15, 16, 17, 17, 18, 18, 19, 19, 21} },
	{  10, {11, 12, 13, 14, 15, 15, 15, 16, 17, 17, 18, 18, 19, 19, 20} },
	{10.5, {10, 12, 13, 14, 15, 15, 15, 16, 17, 17, 18, 18, 18, 19, 20} },
	{  11, { 9, 11, 13, 14, 15, 15, 15, 16, 16, 17, 17, 17, 18, 18, 19} },
	{11.5, { 9, 11, 13, 14, 15, 15, 15, 16, 16, 17, 17, 17, 17, 18, 19} },
	{  12, { 6, 9, 12, 13, 14, 14, 15, 16, 16, 17, 17, 17, 17, 18, 19} },
	{12.5, { 6, 9, 12, 13, 14, 14, 14, 15, 15, 16, 16, 17, 17, 18, 19} },
	{  13, { 5, 9, 12, 13, 13, 14, 14, 15, 15, 16, 16, 16, 16, 17, 18} },
	{13.5, { 5, 8, 11, 12, 12, 13, 13, 14, 14, 15, 15, 16, 16, 17, 18} },
	{  14, { 5, 8, 10, 11, 12, 12, 12, 13, 14, 14, 15, 16, 16, 16, 18} },
	{14.5, { 4, 7, 10, 11, 11, 12, 12, 13, 13, 14, 14, 15, 15, 16, 17} },
	{  15, { 4, 7, 9, 10, 10, 11, 11, 12, 13, 13, 14, 15, 15, 16, 17} },
	{15.5, { 4, 7, 9, 10, 10, 11, 11, 12, 13, 13, 14, 15, 15, 16, 17} },
	{  16, { 4, 7, 9, 10, 10, 11, 11, 12, 13, 13, 13, 14, 14, 15, 16} },
	{16.5, { 4, 5, 7, 8, 10, 11, 11, 12, 13, 13, 13, 14, 14, 15, 16} },
	{  17, { 4, 5, 7, 8, 8, 9, 11, 11, 12, 12, 12, 13, 13, 14, 16} },
	{17.5, { 3, 5, 7, 8, 8, 9, 10, 11, 12, 12, 12, 13, 13, 14, 16} },
	{  18, { 3, 5, 7, 8, 8, 9, 10, 11, 12, 12, 12, 13, 13, 14, 15} },
	{18.5, { 3, 5, 7, 8, 8, 9, 10, 11, 12, 12, 12, 13, 13, 14, 15} },
	{  19, { 3, 4, 6, 7, 8, 8, 9, 10, 11, 11, 11, 12, 12, 13, 14} },
	{19.5, { 3, 4, 6, 7, 8, 8, 9, 10, 11, 11, 11, 12, 12, 13, 14} },
	{  20, { 2, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11, 11, 12, 14} },
	{20.5, { 2, 3, 5, 5, 7, 8, 8, 8, 9, 10, 10, 11, 11, 12, 14} },
	{  21, { 2, 3, 5, 5, 7, 7, 7, 8, 8, 9, 10, 11, 11, 12, 14} },
	{21.5, { 2, 3, 5, 5, 6, 6, 7, 8, 8, 9, 10, 11, 11, 12, 13} },
	{  22, { 2, 2, 4, 5, 6, 6, 7, 7, 8, 9, 10, 10, 10, 11, 13} },
	{22.5, { 2, 2, 4, 5, 5, 6, 7, 7, 8, 9, 10, 10, 10, 11, 12} },
	{  23, { 2, 2, 4, 5, 5, 6, 7, 7, 7, 8, 10, 10, 10, 10, 12} },
	{23.5, { 2, 2, 3, 5, 5, 6, 7, 7, 7, 8, 10, 10, 10, 10, 12} },
	{  24, { 2, 2, 3, 4, 4, 5, 7, 7, 7, 8, 9, 9, 9, 10, 12} },
	{24.5, { 1, 2, 3, 4, 4, 5, 6, 7, 7, 8, 9, 9, 9, 10, 12} },
	{  25, { 1, 2, 3, 3, 4, 5, 6, 6, 7, 8, 9, 9, 9, 9, 11} },
	{25.5, { 1, 1, 3, 3, 4, 5, 6, 6, 7, 7, 8, 9, 9, 9, 11} },
	{  26, { 1, 1, 3, 3, 3, 4, 5, 6, 6, 7, 8, 8, 8, 8, 10} },
	{26.5, { 1, 1, 2, 3, 3, 4, 5, 6, 6, 6, 8, 8, 8, 8, 10} },
	{  27, { 1, 1, 2, 3, 3, 4, 5, 5, 6, 6, 7, 8, 8, 8, 10} },
	{27.5, { 1, 1, 2, 2, 3, 3, 5, 5, 5, 6, 7, 8, 8, 8, 10} },
	{  28, { 0, 1, 1, 2, 2, 3, 4, 5, 5, 5, 7, 7, 7, 8, 10} },
	{28.5, { 0, 1, 1, 2, 2, 3, 4, 4, 5, 5, 6, 7, 7, 7, 9} },
	{  29, { 0, 1, 1, 2, 2, 3, 4, 4, 5, 5, 6, 6, 7, 7, 9} },
	{29.5, { 0, 1, 1, 2, 2, 2, 3, 3, 4, 5, 6, 6, 7, 7, 8} },
	{  30, { 0, 1, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6, 6, 6, 8} },
	{30.5, { 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 5, 5, 5, 6, 8} },
	{  31, { 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 5, 5, 5, 6, 8} },
	{31.5, { 0, 0, 0, 0, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 8} },
	{  32, { 0, 0, 0, 0, 1, 2, 2, 3, 3, 4, 4, 4, 4, 5, 7} },
	{32.5, { 0, 0, 0, 0, 1, 1, 2, 2, 2, 3, 4, 4, 4, 5, 7} },
	{  33, { 0, 0, 0, 0, 1, 1, 2, 2, 2, 3, 3, 4, 4, 4, 6} },
	{33.5, { 0, 0, 0, 0, 1, 1, 2, 2, 2, 3, 3, 4, 4, 4, 6} },
	{  34, { 0, 0, 0, 0, 1, 1, 1, 2, 2, 3, 3, 3, 3, 4, 6} },
	{34.5, { 0, 0, 0, 0, 1, 1, 1, 1, 2, 3, 3, 3, 3, 4, 6} },
	{  35, { 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 5} },
	{35.5, { 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 5} },
	{  36, { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 4} }
};


static const qp_table   qp_table_420_8bpc_min = {
	{   4, { 0, 0, 1, 1, 3, 3, 3, 3, 3, 3, 5, 5, 5, 9, 13} },
	{ 4.5, { 0, 0, 1, 1, 3, 3, 3, 3, 3, 3, 5, 5, 5, 8, 12} },
	{   5, { 0, 0, 1, 1, 3, 3, 3, 3, 3, 3, 5, 5, 5, 8, 12} },
	{ 5.5, { 0, 0, 1, 1, 3, 3, 3, 3, 3, 3, 5, 5, 5, 7, 11} },
	{   6, { 0, 0, 1, 1, 3, 3, 3, 3, 3, 3, 5, 5, 5, 7, 10} },
	{ 6.5, { 0, 0, 1, 1, 2, 2, 3, 3, 3, 3, 4, 5, 5, 7, 10} },
	{   7, { 0, 0, 1, 1, 1, 2, 2, 2, 2, 3, 4, 5, 5, 7, 9} },
	{ 7.5, { 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 4, 4, 5, 7, 8} },
	{   8, { 0, 0, 0, 0, 1, 1, 1, 2, 2, 3, 4, 4, 5, 7, 8} },
	{ 8.5, { 0, 0, 0, 0, 1, 1, 1, 2, 2, 3, 4, 4, 5, 6, 7} },
	{   9, { 0, 0, 0, 0, 1, 1, 1, 2, 2, 3, 3, 4, 5, 5, 6} },
	{ 9.5, { 0, 0, 0, 0, 1, 1, 1, 2, 2, 3, 3, 4, 4, 5, 6} },
	{  10, { 0, 0, 0, 0, 1, 1, 1, 2, 2, 3, 3, 4, 4, 4, 5} },
	{10.5, { 0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 3, 3, 3, 3, 5} },
	{  11, { 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 4} },
	{11.5, { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 3, 4} },
	{  12, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 3} }
};


static const qp_table   qp_table_422_8bpc_min = {
	{   6, { 0, 0, 1, 2, 3, 3, 3, 3, 3, 3, 5, 5, 5, 8, 12} },
	{ 6.5, { 0, 0, 1, 2, 3, 3, 3, 3, 3, 3, 5, 5, 5, 8, 12} },
	{   7, { 0, 0, 1, 2, 3, 3, 3, 3, 3, 3, 5, 5, 5, 7, 11} },
	{ 7.5, { 0, 0, 1, 2, 3, 3, 3, 3, 3, 3, 5, 5, 5, 7, 11} },
	{   8, { 0, 0, 1, 2, 3, 3, 3, 3, 3, 3, 5, 5, 5, 7, 10} },
	{ 8.5, { 0, 0, 1, 2, 2, 2, 2, 3, 3, 3, 4, 5, 5, 7, 10} },
	{   9, { 0, 0, 0, 1, 2, 2, 2, 2, 2, 3, 4, 5, 5, 7, 9} },
	{ 9.5, { 0, 0, 0, 1, 1, 1, 1, 2, 2, 3, 4, 4, 5, 7, 9} },
	{  10, { 0, 0, 0, 0, 1, 1, 1, 2, 2, 3, 4, 4, 5, 7, 8} },
	{10.5, { 0, 0, 0, 0, 1, 1, 1, 2, 2, 3, 4, 4, 5, 7, 8} },
	{  11, { 0, 0, 0, 0, 1, 1, 1, 2, 2, 3, 4, 4, 5, 6, 7} },
	{11.5, { 0, 0, 0, 0, 1, 1, 1, 2, 2, 3, 4, 4, 5, 6, 7} },
	{  12, { 0, 0, 0, 0, 1, 1, 1, 2, 2, 3, 4, 4, 5, 5, 6} },
	{12.5, { 0, 0, 0, 0, 1, 1, 1, 2, 2, 3, 3, 4, 4, 5, 6} },
	{  13, { 0, 0, 0, 0, 1, 1, 1, 2, 2, 3, 3, 3, 4, 4, 5} },
	{13.5, { 0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 3, 3, 3, 4, 5} },
	{  14, { 0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4} },
	{14.5, { 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 3, 4} },
	{  15, { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 4} },
	{15.5, { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 3} },
	{  16, { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 3} }
};


static const qp_table   qp_table_422_10bpc_max = {
	{   6, { 8, 8, 9, 10, 11, 11, 11, 12, 13, 14, 14, 15, 15, 16, 17} },
	{ 6.5, { 8, 8, 9, 10, 11, 11, 11, 12, 13, 14, 14, 15, 15, 16, 17} },
	{   7, { 7, 8, 9, 10, 11, 11, 11, 12, 13, 13, 14, 14, 15, 15, 16} },
	{ 7.5, { 5, 6, 8, 10, 11, 11, 11, 12, 12, 13, 13, 14, 14, 15, 16} },
	{   8, { 4, 6, 7, 9, 10, 11, 11, 12, 12, 13, 13, 13, 13, 14, 15} },
	{ 8.5, { 4, 5, 6, 8, 9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 15} },
	{   9, { 3, 4, 5, 7, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 14} },
	{ 9.5, { 3, 4, 4, 6, 6, 8, 8, 9, 10, 10, 11, 11, 12, 13, 14} },
	{  10, { 2, 3, 3, 5, 5, 7, 7, 8, 9, 9, 10, 11, 11, 12, 13} },
	{10.5, { 2, 3, 3, 5, 5, 6, 7, 8, 9, 9, 10, 11, 11, 12, 13} },
	{  11, { 2, 3, 3, 5, 5, 6, 7, 8, 9, 9, 10, 10, 11, 11, 12} },
	{11.5, { 2, 3, 3, 5, 5, 5, 7, 7, 8, 9, 9, 10, 10, 11, 12} },
	{  12, { 2, 3, 3, 5, 5, 5, 7, 7, 8, 8, 9, 9, 10, 10, 11} },
	{12.5, { 2, 2, 3, 4, 5, 5, 6, 7, 7, 8, 8, 9, 9, 10, 11} },
	{  13, { 1, 2, 3, 4, 5, 5, 6, 7, 7, 8, 8, 8, 9, 9, 10} },
	{13.5, { 1, 2, 3, 3, 4, 5, 6, 6, 7, 7, 8, 8, 8, 9, 10} },
	{  14, { 1, 2, 3, 3, 4, 5, 5, 5, 6, 6, 7, 8, 8, 8, 9} },
	{14.5, { 1, 2, 2, 3, 4, 4, 5, 5, 5, 6, 7, 7, 7, 8, 9} },
	{  15, { 1, 2, 2, 3, 3, 4, 4, 5, 5, 5, 6, 7, 7, 7, 9} },
	{15.5, { 1, 1, 2, 2, 3, 4, 4, 4, 5, 5, 6, 6, 6, 7, 8} },
	{  16, { 1, 1, 2, 2, 3, 4, 4, 4, 5, 5, 6, 6, 6, 6, 8} },
	{16.5, { 0, 1, 1, 2, 2, 3, 3, 4, 4, 4, 4, 5, 5, 6, 7} },
	{  17, { 0, 0, 1, 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 7} },
	{17.5, { 0, 0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 5, 6} },
	{  18, { 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 6} },
	{18.5, { 0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 4, 6} },
	{  19, { 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 5} },
	{19.5, { 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 5} },
	{  20, { 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 4} }
};


static const qp_table qp_table_420_10bpc_max = {
	{   4, { 8, 8, 9, 10, 11, 11, 11, 12, 13, 14, 14, 15, 15, 17, 18} },
	{ 4.5, { 8, 8, 9, 10, 11, 11, 11, 12, 13, 14, 14, 15, 15, 16, 17} },
	{   5, { 7, 8, 9, 10, 11, 11, 11, 12, 13, 13, 14, 14, 15, 16, 17} },
	{ 5.5, { 6, 7, 8, 9, 10, 10, 11, 12, 12, 13, 13, 14, 14, 15, 16} },
	{   6, { 4, 6, 8, 9, 10, 10, 11, 12, 12, 13, 13, 13, 13, 14, 15} },
	{ 6.5, { 4, 5, 7, 8, 8, 9, 10, 11, 11, 12, 12, 13, 13, 14, 15} },
	{   7, { 3, 4, 6, 7, 7, 8, 9, 10, 10, 11, 12, 12, 13, 13, 14} },
	{ 7.5, { 3, 4, 5, 6, 6, 7, 8, 9, 10, 10, 11, 11, 12, 12, 13} },
	{   8, { 2, 3, 4, 5, 5, 6, 7, 8, 9, 9, 10, 11, 11, 12, 13} },
	{ 8.5, { 1, 3, 3, 4, 4, 6, 7, 8, 9, 9, 10, 10, 11, 11, 12} },
	{   9, { 1, 3, 3, 4, 4, 6, 7, 8, 8, 9, 9, 10, 10, 10, 11} },
	{ 9.5, { 1, 3, 3, 3, 4, 5, 6, 7, 8, 8, 9, 9, 9, 10, 11} },
	{  10, { 1, 2, 3, 3, 4, 4, 5, 6, 7, 8, 8, 9, 9, 9, 11} },
	{10.5, { 1, 1, 3, 3, 3, 4, 5, 5, 7, 7, 8, 8, 8, 8, 10} },
	{  11, { 0, 1, 2, 3, 3, 3, 4, 5, 6, 7, 7, 7, 8, 8, 9} },
	{11.5, { 0, 1, 1, 2, 3, 3, 3, 4, 5, 6, 6, 7, 7, 7, 9} },
	{  12, { 0, 0, 1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6, 6, 8} },
	{12.5, { 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 5, 6, 7} },
	{  13, { 0, 0, 0, 1, 2, 2, 3, 3, 3, 4, 4, 5, 5, 5, 7} },
	{13.5, { 0, 0, 0, 1, 1, 2, 2, 2, 3, 3, 4, 4, 4, 4, 6} },
	{  14, { 0, 0, 0, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 6} },
	{14.5, { 0, 0, 0, 0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 5} },
	{  15, { 0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 2, 3, 5} }
};


static const qp_table   qp_table_420_10bpc_min = {
	{   4, { 0, 4, 4, 5, 7, 7, 7, 7, 7, 7, 9, 9, 9, 13, 17} },
	{ 4.5, { 0, 4, 4, 5, 7, 7, 7, 7, 7, 7, 9, 9, 9, 12, 16} },
	{   5, { 0, 4, 4, 5, 7, 7, 7, 7, 7, 7, 9, 9, 9, 12, 16} },
	{ 5.5, { 0, 3, 3, 4, 6, 7, 7, 7, 7, 7, 9, 9, 9, 11, 15} },
	{   6, { 0, 2, 3, 4, 6, 7, 7, 7, 7, 7, 9, 9, 9, 11, 14} },
	{ 6.5, { 0, 2, 3, 4, 5, 6, 6, 7, 7, 7, 8, 9, 9, 11, 14} },
	{   7, { 0, 2, 3, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 11, 13} },
	{ 7.5, { 0, 2, 3, 4, 4, 5, 5, 6, 7, 7, 8, 8, 9, 11, 12} },
	{   8, { 0, 2, 3, 4, 4, 5, 5, 6, 6, 7, 8, 8, 9, 11, 12} },
	{ 8.5, { 0, 2, 2, 3, 3, 5, 5, 6, 6, 7, 8, 8, 9, 10, 11} },
	{   9, { 0, 2, 2, 3, 3, 5, 5, 6, 6, 7, 7, 8, 9, 9, 10} },
	{ 9.5, { 0, 2, 2, 2, 3, 4, 4, 5, 6, 6, 7, 8, 8, 9, 10} },
	{  10, { 0, 1, 2, 2, 3, 3, 4, 4, 5, 6, 6, 8, 8, 8, 10} },
	{10.5, { 0, 0, 2, 2, 2, 3, 4, 4, 5, 5, 6, 7, 7, 7, 9} },
	{  11, { 0, 0, 1, 2, 2, 2, 3, 4, 4, 5, 5, 6, 7, 7, 8} },
	{11.5, { 0, 0, 0, 1, 2, 2, 2, 3, 4, 4, 5, 6, 6, 6, 8} },
	{  12, { 0, 0, 0, 0, 1, 1, 2, 2, 3, 4, 4, 5, 5, 5, 7} },
	{12.5, { 0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 4, 5, 6} },
	{  13, { 0, 0, 0, 0, 1, 1, 2, 2, 2, 3, 3, 4, 4, 4, 6} },
	{13.5, { 0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 3, 3, 3, 3, 5} },
	{  14, { 0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 5} },
	{14.5, { 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 4} },
	{  15, { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 4} }
};


static const qp_table   qp_table_444_10bpc_max = {
	{   6, { 8, 10, 12, 12, 13, 13, 13, 14, 15, 16, 16, 16, 16, 17, 19} },
	{ 6.5, { 8, 10, 11, 12, 12, 12, 13, 14, 15, 15, 16, 16, 16, 17, 19} },
	{   7, { 8, 9, 11, 11, 12, 12, 12, 13, 14, 15, 15, 16, 16, 17, 18} },
	{ 7.5, { 8, 9, 10, 11, 11, 12, 12, 13, 14, 14, 15, 15, 16, 17, 18} },
	{   8, { 8, 8, 9, 10, 11, 11, 11, 12, 13, 14, 14, 15, 15, 16, 17} },
	{ 8.5, { 8, 8, 9, 10, 11, 11, 11, 12, 13, 14, 14, 15, 15, 16, 17} },
	{   9, { 7, 8, 9, 10, 11, 11, 11, 12, 13, 13, 14, 14, 15, 15, 17} },
	{ 9.5, { 7, 8, 9, 10, 11, 11, 11, 12, 13, 13, 14, 14, 15, 15, 17} },
	{  10, { 7, 8, 9, 10, 11, 11, 11, 12, 13, 13, 14, 14, 15, 15, 16} },
	{10.5, { 6, 8, 9, 10, 11, 11, 11, 12, 13, 13, 14, 14, 14, 15, 16} },
	{  11, { 5, 7, 9, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15} },
	{11.5, { 5, 7, 9, 10, 11, 11, 11, 12, 12, 13, 13, 13, 13, 14, 15} },
	{  12, { 4, 6, 8, 9, 10, 10, 11, 12, 12, 13, 13, 13, 13, 14, 15} },
	{12.5, { 4, 6, 8, 9, 10, 10, 10, 11, 11, 12, 12, 13, 13, 14, 15} },
	{  13, { 3, 6, 8, 9, 9, 10, 10, 11, 11, 12, 12, 12, 12, 13, 14} },
	{13.5, { 3, 5, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 14} },
	{  14, { 3, 5, 6, 7, 8, 8, 8, 9, 10, 10, 11, 12, 12, 12, 14} },
	{14.5, { 2, 4, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 13} },
	{  15, { 2, 4, 5, 6, 6, 7, 7, 8, 9, 9, 10, 11, 11, 12, 13} },
	{15.5, { 2, 4, 5, 6, 6, 7, 7, 8, 9, 9, 10, 11, 11, 12, 13} },
	{  16, { 2, 4, 5, 6, 6, 7, 7, 8, 9, 9, 9, 10, 10, 11, 12} },
	{16.5, { 2, 3, 4, 5, 6, 7, 7, 8, 9, 9, 9, 10, 10, 11, 12} },
	{  17, { 2, 3, 4, 5, 5, 6, 7, 7, 8, 8, 8, 9, 9, 10, 12} },
	{17.5, { 1, 3, 4, 5, 5, 6, 6, 7, 8, 8, 8, 9, 9, 10, 12} },
	{  18, { 1, 3, 4, 5, 5, 6, 6, 7, 8, 8, 8, 9, 9, 10, 11} },
	{18.5, { 1, 3, 4, 5, 5, 6, 6, 7, 8, 8, 8, 9, 9, 10, 11} },
	{  19, { 1, 2, 3, 4, 5, 5, 5, 6, 7, 7, 7, 8, 8, 9, 10} },
	{19.5, { 1, 2, 3, 4, 5, 5, 5, 6, 7, 7, 7, 8, 8, 9, 10} },
	{  20, { 1, 2, 3, 3, 4, 5, 5, 6, 6, 6, 6, 7, 7, 8, 10} },
	{20.5, { 1, 2, 3, 3, 4, 5, 5, 5, 5, 6, 6, 7, 7, 8, 10} },
	{  21, { 1, 2, 3, 3, 4, 4, 4, 5, 5, 5, 6, 7, 7, 8, 10} },
	{21.5, { 1, 2, 3, 3, 3, 3, 4, 5, 5, 5, 6, 7, 7, 8, 9} },
	{  22, { 1, 1, 2, 3, 3, 3, 4, 4, 5, 5, 6, 6, 6, 7, 9} },
	{22.5, { 1, 1, 2, 3, 3, 3, 4, 4, 5, 5, 6, 6, 6, 7, 8} },
	{  23, { 1, 1, 2, 3, 3, 3, 4, 4, 4, 4, 6, 6, 6, 6, 8} },
	{23.5, { 1, 1, 1, 3, 3, 3, 4, 4, 4, 4, 6, 6, 6, 6, 8} },
	{  24, { 1, 1, 1, 2, 2, 3, 4, 4, 4, 4, 5, 5, 5, 6, 8} },
	{24.5, { 0, 1, 1, 2, 2, 3, 3, 4, 4, 4, 5, 5, 5, 6, 8} },
	{  25, { 0, 1, 1, 1, 2, 3, 3, 3, 4, 4, 5, 5, 5, 5, 7} },
	{25.5, { 0, 0, 1, 1, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 7} },
	{  26, { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4, 4, 4, 4, 4, 6} },
	{26.5, { 0, 0, 0, 1, 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 6} },
	{  27, { 0, 0, 0, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 6} },
	{27.5, { 0, 0, 0, 0, 1, 1, 2, 2, 2, 3, 3, 4, 4, 4, 6} },
	{  28, { 0, 0, 0, 0, 0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 5} },
	{28.5, { 0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 5} },
	{  29, { 0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 3, 3, 4} },
	{29.5, { 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 4} },
	{  30, { 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 4} }
};


static const qp_table   qp_table_422_8bpc_max = {
	{   6, { 4, 4, 5, 6, 7, 7, 7, 8, 9, 10, 10, 11, 11, 12, 13} },
	{ 6.5, { 4, 4, 5, 6, 7, 7, 7, 8, 9, 10, 10, 11, 11, 12, 13} },
	{   7, { 3, 4, 5, 6, 7, 7, 7, 8, 9, 9, 10, 10, 11, 11, 12} },
	{ 7.5, { 3, 4, 5, 6, 7, 7, 7, 8, 8, 9, 9, 10, 10, 11, 12} },
	{   8, { 2, 4, 5, 6, 7, 7, 7, 8, 8, 9, 9, 9, 9, 10, 11} },
	{ 8.5, { 2, 3, 4, 5, 6, 6, 6, 7, 7, 8, 8, 9, 9, 10, 11} },
	{   9, { 1, 2, 3, 4, 5, 5, 5, 6, 6, 7, 7, 8, 8, 9, 10} },
	{ 9.5, { 1, 2, 2, 3, 3, 4, 4, 5, 6, 6, 7, 7, 8, 9, 10} },
	{  10, { 0, 1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 7, 7, 8, 9} },
	{10.5, { 0, 1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 7, 7, 8, 9} },
	{  11, { 0, 1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6, 7, 7, 8} },
	{11.5, { 0, 1, 1, 2, 2, 2, 3, 3, 4, 5, 5, 6, 6, 7, 8} },
	{  12, { 0, 1, 1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7} },
	{12.5, { 0, 0, 1, 1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 7} },
	{  13, { 0, 0, 1, 1, 2, 2, 2, 3, 3, 4, 4, 4, 5, 5, 6} },
	{13.5, { 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 4, 4, 4, 5, 6} },
	{  14, { 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5} },
	{14.5, { 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 5} },
	{  15, { 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 5} },
	{15.5, { 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 4} },
	{  16, { 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 4} }
};

