/*
 * Copyright (c) 2016-2017  Moddable Tech, Inc.
 *
 *   This file is part of the Moddable SDK Runtime.
 * 
 *   The Moddable SDK Runtime is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU Lesser General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 * 
 *   The Moddable SDK Runtime is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU Lesser General Public License for more details.
 * 
 *   You should have received a copy of the GNU Lesser General Public License
 *   along with the Moddable SDK Runtime.  If not, see <http://www.gnu.org/licenses/>.
 *
 * This file incorporates work covered by the following copyright and  
 * permission notice:  
 *
 *       Copyright (C) 2010-2016 Marvell International Ltd.
 *       Copyright (C) 2002-2010 Kinoma, Inc.
 *
 *       Licensed under the Apache License, Version 2.0 (the "License");
 *       you may not use this file except in compliance with the License.
 *       You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *       Unless required by applicable law or agreed to in writing, software
 *       distributed under the License is distributed on an "AS IS" BASIS,
 *       WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *       See the License for the specific language governing permissions and
 *       limitations under the License.
 */

#include "xsCommon.h"

static txBoolean fxIsSpace(txU4 c);

const txString gxCodeNames[XS_CODE_COUNT] = {
	"",
	/* XS_CODE_ADD */ "add",
	/* XS_CODE_ARGUMENT */ "argument",
	/* XS_CODE_ARGUMENTS */ "arguments",
	/* XS_CODE_ARGUMENTS_SLOPPY */ "arguments_sloppy",
	/* XS_CODE_ARGUMENTS_STRICT */ "arguments_strict",
	/* XS_CODE_ARRAY */ "array",
	/* XS_CODE_ASYNC_FUNCTION */ "async_function",
	/* XS_CODE_AT */ "at",
	/* XS_CODE_AWAIT */ "await",
	/* XS_CODE_BEGIN_SLOPPY */ "begin_sloppy",
	/* XS_CODE_BEGIN_STRICT */ "begin_strict",
	/* XS_CODE_BEGIN_STRICT_BASE */ "begin_strict_base",
	/* XS_CODE_BEGIN_STRICT_DERIVED */ "begin_strict_derived",
	/* XS_CODE_BIT_AND */ "bit_and",
	/* XS_CODE_BIT_NOT */ "bit_not",
	/* XS_CODE_BIT_OR */ "bit_or",
	/* XS_CODE_BIT_XOR */ "bit_xor",
	/* XS_CODE_BRANCH_1 */ "branch",
	/* XS_CODE_BRANCH_2 */ "branch_2",
	/* XS_CODE_BRANCH_4 */ "branch_4",
	/* XS_CODE_BRANCH_ELSE_1 */ "branch_else",
	/* XS_CODE_BRANCH_ELSE_2 */ "branch_else_2",
	/* XS_CODE_BRANCH_ELSE_4 */ "branch_else_4",
	/* XS_CODE_BRANCH_IF_1 */ "branch_if",
	/* XS_CODE_BRANCH_IF_2 */ "branch_if_2",
	/* XS_CODE_BRANCH_IF_4 */ "branch_if_4",
	/* XS_CODE_BRANCH_STATUS_1 */ "branch_status",
	/* XS_CODE_BRANCH_STATUS_2 */ "branch_status_2",
	/* XS_CODE_BRANCH_STATUS_4 */ "branch_status_4",
	/* XS_CODE_CALL */ "call",
	/* XS_CODE_CALL_TAIL */ "call_tail",
	/* XS_CODE_CATCH_1 */ "catch",
	/* XS_CODE_CATCH_2 */ "catch_2",
	/* XS_CODE_CATCH_4 */ "catch_4",
	/* XS_CODE_CHECK_INSTANCE */ "check_instance",
	/* XS_CODE_CLASS */ "class",
	/* XS_CODE_CODE_1 */ "code",
	/* XS_CODE_CODE_2 */ "code_2",
	/* XS_CODE_CODE_4 */ "code_4",
	/* XS_CODE_CODE_ARCHIVE_1 */ "code_archive",
	/* XS_CODE_CODE_ARCHIVE_2 */ "code_archive_2",
	/* XS_CODE_CODE_ARCHIVE_4 */ "code_archive_4",
	/* XS_CODE_CONST_CLOSURE_1 */ "const_closure",
	/* XS_CODE_CONST_CLOSURE_2 */ "const_closure_2",
	/* XS_CODE_CONST_LOCAL_1 */ "const_local",
	/* XS_CODE_CONST_LOCAL_2 */ "const_local_2",
	/* XS_CODE_CONSTRUCTOR_FUNCTION */ "constructor_function",
	/* XS_CODE_CURRENT */ "current",
	/* XS_CODE_DEBUGGER */ "debugger",
	/* XS_CODE_DECREMENT */ "decrement",
	/* XS_CODE_DELETE_PROPERTY */ "delete_property",
	/* XS_CODE_DELETE_PROPERTY_AT */ "delete_property_at",
	/* XS_CODE_DELETE_SUPER */ "delete_super",
	/* XS_CODE_DELETE_SUPER_AT */ "delete_super_at",
	/* XS_CODE_DIVIDE */ "divide",
	/* XS_CODE_DUB */ "dub",
	/* XS_CODE_DUB_AT */ "dub_at",
	/* XS_CODE_END */ "end",
	/* XS_CODE_END_ARROW */ "end_arrow",
	/* XS_CODE_END_BASE */ "end_base",
	/* XS_CODE_END_DERIVED */ "end_derived",
	/* XS_CODE_ENVIRONMENT */ "environment",
	/* XS_CODE_EQUAL */ "equal",
	/* XS_CODE_EVAL */ "eval",
	/* XS_CODE_EVAL_REFERENCE */ "eval_reference",
	/* XS_CODE_EVAL_VARIABLE */ "eval_variable",
	/* XS_CODE_EXCEPTION */ "exception",
	/* XS_CODE_EXPONENTIATION */ "exponentiation",
	/* XS_CODE_EXTEND */ "extend",
	/* XS_CODE_FALSE */ "false",
	/* XS_CODE_FILE */ "file",
	/* XS_CODE_FOR_IN */ "for_in",
	/* XS_CODE_FOR_OF */ "for_of",
	/* XS_CODE_FUNCTION */ "function",
	/* XS_CODE_GENERATOR_FUNCTION */ "generator",
	/* XS_CODE_GET_CLOSURE_1 */ "get_closure",
	/* XS_CODE_GET_CLOSURE_2 */ "get_closure_2",
	/* XS_CODE_GET_LOCAL_1 */ "get_local",
	/* XS_CODE_GET_LOCAL_2 */ "get_local_2",
	/* XS_CODE_GET_PROPERTY */ "get_property",
	/* XS_CODE_GET_PROPERTY_AT */ "get_property_at",
	/* XS_CODE_GET_SUPER */ "get_super",
	/* XS_CODE_GET_SUPER_AT */ "get_super_at",
	/* XS_CODE_GET_THIS */ "get_this",
	/* XS_CODE_GET_VARIABLE */ "get_variable",
	/* XS_CODE_GLOBAL */ "global",
	/* XS_CODE_HOST */ "host",
	/* XS_CODE_IN */ "in",
	/* XS_CODE_INCREMENT */ "increment",
	/* XS_CODE_INSTANCEOF */ "instanceof",
	/* XS_CODE_INSTANTIATE */ "instantiate",
	/* XS_CODE_INTEGER_1 */ "integer",
	/* XS_CODE_INTEGER_2 */ "integer_2",
	/* XS_CODE_INTEGER_4 */ "integer_4",
	/* XS_CODE_LEFT_SHIFT */ "left_shift",
	/* XS_CODE_LESS */ "less",
	/* XS_CODE_LESS_EQUAL */ "less_equal",
	/* XS_CODE_LET_CLOSURE_1 */ "let_closure",
	/* XS_CODE_LET_CLOSURE_2 */ "let_closure_2",
	/* XS_CODE_LET_LOCAL_1 */ "let_local",
	/* XS_CODE_LET_LOCAL_2 */ "let_local_2",
	/* XS_CODE_LINE */ "line",
	/* XS_CODE_MINUS */ "minus",
	/* XS_CODE_MODULE */ "module",
	/* XS_CODE_MODULO */ "modulo",
	/* XS_CODE_MORE */ "more",
	/* XS_CODE_MORE_EQUAL */ "more_equal",
	/* XS_CODE_MULTIPLY */ "multiply",
	/* XS_CODE_NAME */ "name",
	/* XS_CODE_NEW */ "new",
	/* XS_CODE_NEW_CLOSURE */ "new_closure",
	/* XS_CODE_NEW_LOCAL */ "new_local",
	/* XS_CODE_NEW_PROPERTY */ "new_property",
	/* XS_CODE_NEW_TEMPORARY */ "new_temporary",
	/* XS_CODE_NOT */ "not",
	/* XS_CODE_NOT_EQUAL */ "not_equal",
	/* XS_CODE_NULL */ "null",
	/* XS_CODE_NUMBER */ "number",
	/* XS_CODE_OBJECT */ "object",
	/* XS_CODE_PLUS */ "plus",
	/* XS_CODE_POP */ "pop",
	/* XS_CODE_PROGRAM_VARIABLE */ "program_variable",
	/* XS_CODE_PULL_CLOSURE_1 */ "pull_closure",
	/* XS_CODE_PULL_CLOSURE_2 */ "pull_closure_2",
	/* XS_CODE_PULL_LOCAL_1 */ "pull_local",
	/* XS_CODE_PULL_LOCAL_2 */ "pull_local_2",
	/* XS_CODE_REFRESH_CLOSURE_1 */ "refresh_closure",
	/* XS_CODE_REFRESH_CLOSURE_2 */ "refresh_closure_2",
	/* XS_CODE_REFRESH_LOCAL_1 */ "refresh_local",
	/* XS_CODE_REFRESH_LOCAL_2 */ "refresh_local_2",
	/* XS_CODE_RESERVE_1 */ "reserve",
	/* XS_CODE_RESERVE_2 */ "reserve_2",
	/* XS_CODE_RESET_CLOSURE_1 */ "reset_closure",
	/* XS_CODE_RESET_CLOSURE_2 */ "reset_closure_2",
	/* XS_CODE_RESET_LOCAL_1 */ "reset_local",
	/* XS_CODE_RESET_LOCAL_2 */ "reset_local_2",
	/* XS_CODE_RESULT */ "result",
	/* XS_CODE_RETHROW */ "rethrow",
	/* XS_CODE_RETRIEVE_1 */ "retrieve",
	/* XS_CODE_RETRIEVE_2 */ "retrieve_2",
	/* XS_CODE_RETRIEVE_TARGET */ "retrieve_target",
	/* XS_CODE_RETRIEVE_THIS */ "retrieve_this",
	/* XS_CODE_RETURN */ "return",
	/* XS_CODE_SET_CLOSURE_1 */ "set_closure",
	/* XS_CODE_SET_CLOSURE_2 */ "set_closure_2",
	/* XS_CODE_SET_LOCAL_1 */ "set_local",
	/* XS_CODE_SET_LOCAL_2 */ "set_local_2",
	/* XS_CODE_SET_PROPERTY */ "set_property",
	/* XS_CODE_SET_PROPERTY_AT */ "set_property_at",
	/* XS_CODE_SET_SUPER */ "set_super",
	/* XS_CODE_SET_SUPER_AT */ "set_super_at",
	/* XS_CODE_SET_THIS */ "set_this",
	/* XS_CODE_SET_VARIABLE */ "set_variable",
	/* XS_CODE_SIGNED_RIGHT_SHIFT */ "signed_right_shift",
	/* XS_CODE_START_ASYNC */ "start_async",
	/* XS_CODE_START_GENERATOR */ "start_generator",
	/* XS_CODE_STORE_1 */ "store_1",
	/* XS_CODE_STORE_2 */ "store_2",
	/* XS_CODE_STORE_ARROW */ "store_arrow",
	/* XS_CODE_STRICT_EQUAL */ "strict_equal",
	/* XS_CODE_STRICT_NOT_EQUAL */ "strict_not_equal",
	/* XS_CODE_STRING_1 */ "string",
	/* XS_CODE_STRING_2 */ "string_2",
	/* XS_CODE_STRING_ARCHIVE_1 */ "string_archive",
	/* XS_CODE_STRING_ARCHIVE_2 */ "string_archive_2",
	/* XS_CODE_SUBTRACT */ "subtract",
	/* XS_CODE_SUPER */ "super",
	/* XS_CODE_SWAP */ "swap",
	/* XS_CODE_SYMBOL */ "symbol",
	/* XS_CODE_TARGET */ "target",
	/* XS_CODE_TEMPLATE */ "template",
	/* XS_CODE_THIS */ "this",
	/* XS_CODE_THROW */ "throw",
	/* XS_CODE_TO_INSTANCE */ "to_instance",
	/* XS_CODE_TRANSFER */ "transfer",
	/* XS_CODE_TRUE */ "true",
	/* XS_CODE_TYPEOF */ "typeof",
	/* XS_CODE_UNCATCH */ "uncatch",
	/* XS_CODE_UNDEFINED */ "undefined",
	/* XS_CODE_UNSIGNED_RIGHT_SHIFT */ "unsigned_right_shift",
	/* XS_CODE_UNWIND_1 */ "unwind",
	/* XS_CODE_UNWIND_2 */ "unwind_2",
	/* XS_CODE_VAR_CLOSURE_1 */ "var_closure_1",
	/* XS_CODE_VAR_CLOSURE */ "var_closure",
	/* XS_CODE_VAR_LOCAL_1 */ "var_local_1",
	/* XS_CODE_VAR_LOCAL_2 */ "var_local_2",
	/* XS_CODE_VOID */ "void",
	/* XS_CODE_WITH */ "with",
	/* XS_CODE_WITHOUT */ "without",
	/* XS_CODE_YIELD */ "yield"
};

const txS1 gxCodeSizes[XS_CODE_COUNT] ICACHE_FLASH_ATTR = {
	0 /* XS_NO_CODE */,
	1 /* XS_CODE_ADD */,
	2 /* XS_CODE_ARGUMENT */,
	2 /* XS_CODE_ARGUMENTS */,
	2 /* XS_CODE_ARGUMENTS_SLOPPY */,
	2 /* XS_CODE_ARGUMENTS_STRICT */,
	1 /* XS_CODE_ARRAY */,
	0 /* XS_CODE_ASYNC_FUNCTION */,
	1 /* XS_CODE_AT */,
	1 /* XS_CODE_AWAIT */,
	2 /* XS_CODE_BEGIN_SLOPPY */,
	2 /* XS_CODE_BEGIN_STRICT */,
	2 /* XS_CODE_BEGIN_STRICT_BASE */,
	2 /* XS_CODE_BEGIN_STRICT_DERIVED */,
	1 /* XS_CODE_BIT_AND */,
	1 /* XS_CODE_BIT_NOT */,
	1 /* XS_CODE_BIT_OR */,
	1 /* XS_CODE_BIT_XOR */,
	2 /* XS_CODE_BRANCH_1 */,
	3 /* XS_CODE_BRANCH_2 */,
	5 /* XS_CODE_BRANCH_4 */,
	2 /* XS_CODE_BRANCH_ELSE_1 */,
	3 /* XS_CODE_BRANCH_ELSE_2 */,
	5 /* XS_CODE_BRANCH_ELSE_4 */,
	2 /* XS_CODE_BRANCH_IF_1 */,
	3 /* XS_CODE_BRANCH_IF_2 */,
	5 /* XS_CODE_BRANCH_IF_4 */,
	2 /* XS_CODE_BRANCH_STATUS_1 */,
	3 /* XS_CODE_BRANCH_STATUS_2 */,
	5 /* XS_CODE_BRANCH_STATUS_4 */,
	1 /* XS_CODE_CALL */,
	1 /* XS_CODE_CALL_TAIL */,
	2 /* XS_CODE_CATCH_1 */,
	3 /* XS_CODE_CATCH_2 */,
	5 /* XS_CODE_CATCH_4 */,
	1 /* XS_CODE_CLASS */,
	1 /* XS_CODE_CHECK_INSTANCE */,
	2 /* XS_CODE_CODE_1 */,
	3 /* XS_CODE_CODE_2 */,
	5 /* XS_CODE_CODE_4 */,
	2 /* XS_CODE_CODE_ARCHIVE_1 */,
	3 /* XS_CODE_CODE_ARCHIVE_2 */,
	5 /* XS_CODE_CODE_ARCHIVE_4 */,
	2 /* XS_CODE_CONST_CLOSURE_1 */,
	3 /* XS_CODE_CONST_CLOSURE_2 */,
	2 /* XS_CODE_CONST_LOCAL_1 */,
	3 /* XS_CODE_CONST_LOCAL_2 */,
	0 /* XS_CODE_CONSTRUCTOR_FUNCTION */,
	1 /* XS_CODE_CURRENT */,
	1 /* XS_CODE_DEBUGGER */,
	1 /* XS_CODE_DECREMENT */,
	0 /* XS_CODE_DELETE_PROPERTY */,
	1 /* XS_CODE_DELETE_PROPERTY_AT */,
	0 /* XS_CODE_DELETE_SUPER */,
	1 /* XS_CODE_DELETE_SUPER_AT */,
	1 /* XS_CODE_DIVIDE */,
	1 /* XS_CODE_DUB */,
	1 /* XS_CODE_DUB_AT */,
	1 /* XS_CODE_END */,
	1 /* XS_CODE_END_ARROW */,
	1 /* XS_CODE_END_BASE */,
	1 /* XS_CODE_END_DERIVED */,
	1 /* XS_CODE_ENVIRONMENT */,
	1 /* XS_CODE_EQUAL */,
	1 /* XS_CODE_EVAL */,
	0 /* XS_CODE_EVAL_REFERENCE */,
	0 /* XS_CODE_EVAL_VARIABLE */,
	1 /* XS_CODE_EXCEPTION */,
	1 /* XS_CODE_EXPONENTIATION */,
	1 /* XS_CODE_EXTEND */,
	1 /* XS_CODE_FALSE */,
	0 /* XS_CODE_FILE */,
	1 /* XS_CODE_FOR_IN */,
	1 /* XS_CODE_FOR_OF */,
	0 /* XS_CODE_FUNCTION */,
	0 /* XS_CODE_GENERATOR_FUNCTION */,
	2 /* XS_CODE_GET_CLOSURE_1 */,
	3 /* XS_CODE_GET_CLOSURE_2 */,
	2 /* XS_CODE_GET_LOCAL_1 */,
	3 /* XS_CODE_GET_LOCAL_2 */,
	0 /* XS_CODE_GET_PROPERTY */,
	1 /* XS_CODE_GET_PROPERTY_AT */,
	0 /* XS_CODE_GET_SUPER */,
	1 /* XS_CODE_GET_SUPER_AT */,
	1 /* XS_CODE_GET_THIS */,
	0 /* XS_CODE_GET_VARIABLE */,
	1 /* XS_CODE_GLOBAL */,
	3 /* XS_CODE_HOST */,
	1 /* XS_CODE_IN */,
	1 /* XS_CODE_INCREMENT */,
	1 /* XS_CODE_INSTANCEOF */,
	1 /* XS_CODE_INSTANTIATE */,
	2 /* XS_CODE_INTEGER_1 */,
	3 /* XS_CODE_INTEGER_2 */,
	5 /* XS_CODE_INTEGER_4 */,
	1 /* XS_CODE_LEFT_SHIFT */,
	1 /* XS_CODE_LESS */,
	1 /* XS_CODE_LESS_EQUAL */,
	2 /* XS_CODE_LET_CLOSURE_1 */,
	3 /* XS_CODE_LET_CLOSURE_2 */,
	2 /* XS_CODE_LET_LOCAL_1 */,
	3 /* XS_CODE_LET_LOCAL_2 */,
	3 /* XS_CODE_LINE */,
	1 /* XS_CODE_MINUS */,
	1 /* XS_CODE_MODULE */,
	1 /* XS_CODE_MODULO */,
	1 /* XS_CODE_MORE */,
	1 /* XS_CODE_MORE_EQUAL */,
	1 /* XS_CODE_MULTIPLY */,
	0 /* XS_CODE_NAME */,
	1 /* XS_CODE_NEW */,
	0 /* XS_CODE_NEW_CLOSURE */,
	0 /* XS_CODE_NEW_LOCAL */,
	2 /* XS_CODE_NEW_PROPERTY */,
	1 /* XS_CODE_NEW_TEMPORARY */,
	1 /* XS_CODE_NOT */,
	1 /* XS_CODE_NOT_EQUAL */,
	1 /* XS_CODE_NULL */,
	9 /* XS_CODE_NUMBER */,
	1 /* XS_CODE_OBJECT */,
	1 /* XS_CODE_PLUS */,
	1 /* XS_CODE_POP */,
	0 /* XS_CODE_PROGRAM_VARIABLE */,
	2 /* XS_CODE_PULL_CLOSURE_1 */,
	3 /* XS_CODE_PULL_CLOSURE_2 */,
	2 /* XS_CODE_PULL_LOCAL_1 */,
	3 /* XS_CODE_PULL_LOCAL_2 */,
	2 /* XS_CODE_REFRESH_CLOSURE_1 */,
	3 /* XS_CODE_REFRESH_CLOSURE_2 */,
	2 /* XS_CODE_REFRESH_LOCAL_1 */,
	3 /* XS_CODE_REFRESH_LOCAL_2 */,
	2 /* XS_CODE_RESERVE_1 */,
	3 /* XS_CODE_RESERVE_2 */,
	2 /* XS_CODE_RESET_CLOSURE_1 */,
	3 /* XS_CODE_RESET_CLOSURE_2 */,
	2 /* XS_CODE_RESET_LOCAL_1 */,
	3 /* XS_CODE_RESET_LOCAL_2 */,
	1 /* XS_CODE_RESULT */,
	1 /* XS_CODE_RETHROW */,
	2 /* XS_CODE_RETRIEVE_1 */,
	3 /* XS_CODE_RETRIEVE_2 */,
	1 /* XS_CODE_RETRIEVE_TARGET */,
	1 /* XS_CODE_RETRIEVE_THIS */,
	1 /* XS_CODE_RETURN */,
	2 /* XS_CODE_SET_CLOSURE_1 */,
	3 /* XS_CODE_SET_CLOSURE_2 */,
	2 /* XS_CODE_SET_LOCAL_1 */,
	3 /* XS_CODE_SET_LOCAL_2 */,
	0 /* XS_CODE_SET_PROPERTY */,
	1 /* XS_CODE_SET_PROPERTY_AT */,
	0 /* XS_CODE_SET_SUPER */,
	1 /* XS_CODE_SET_SUPER_AT */,
	1 /* XS_CODE_SET_THIS */,
	0 /* XS_CODE_SET_VARIABLE */,
	1 /* XS_CODE_SIGNED_RIGHT_SHIFT */,
	1 /* XS_CODE_START_ASYNC */,
	1 /* XS_CODE_START_GENERATOR */,
	2 /* XS_CODE_STORE_1 */,
	3 /* XS_CODE_STORE_2 */,
	1 /* XS_CODE_STORE_ARROW */,
	1 /* XS_CODE_STRICT_EQUAL */,
	1 /* XS_CODE_STRICT_NOT_EQUAL */,
	-1 /* XS_CODE_STRING_1 */,
	-2 /* XS_CODE_STRING_2 */,
	-1 /* XS_CODE_STRING_ARCHIVE_1 */,
	-2 /* XS_CODE_STRING_ARCHIVE_2 */,
	1 /* XS_CODE_SUBTRACT */,
	1 /* XS_CODE_SUPER */,
	1 /* XS_CODE_SWAP */,
	0 /* XS_CODE_SYMBOL */,
	1 /* XS_CODE_TARGET */,
	1 /* XS_CODE_TEMPLATE */,
	1 /* XS_CODE_THIS */,
	1 /* XS_CODE_THROW */,
	1 /* XS_CODE_TO_INSTANCE */,
	1 /* XS_CODE_TRANSFER */,
	1 /* XS_CODE_TRUE */,
	1 /* XS_CODE_TYPEOF */,
	1 /* XS_CODE_UNCATCH */,
	1 /* XS_CODE_UNDEFINED */,
	1 /* XS_CODE_UNSIGNED_RIGHT_SHIFT */,
	2 /* XS_CODE_UNWIND_1 */,
	3 /* XS_CODE_UNWIND_2 */,
	2 /* XS_CODE_VAR_CLOSURE_1 */,
	3 /* XS_CODE_VAR_CLOSURE_2 */,
	2 /* XS_CODE_VAR_LOCAL_1 */,
	3 /* XS_CODE_VAR_LOCAL_2 */,
	1 /* XS_CODE_VOID */,
	1 /* XS_CODE_WITH */,
	1 /* XS_CODE_WITHOUT */,
	1 /* XS_CODE_YIELD */
};

const txUTF8Sequence gxUTF8Sequences[] ICACHE_RODATA_ATTR = {
	{1, 0x80, 0x00, 0*6, 0x0000007F, 0x00000000},
	{2, 0xE0, 0xC0, 1*6, 0x000007FF, 0x00000080},
	{3, 0xF0, 0xE0, 2*6, 0x0000FFFF, 0x00000800},
	{4, 0xF8, 0xF0, 3*6, 0x001FFFFF, 0x00010000},
	{5, 0xFC, 0xF8, 4*6, 0x03FFFFFF, 0x00200000},
	{6, 0xFE, 0xFC, 5*6, 0x7FFFFFFF, 0x04000000},
	{0, 0, 0, 0, 0, 0},
};

/* compressed from http://www-01.ibm.com/support/knowledgecenter/#!/ssw_ibm_i_71/nls/rbagslowtoupmaptable.htm */
const txCharCase gxCharCaseToLower[mxCharCaseToLowerCount] ICACHE_XS6RO_ATTR = {
	{0x0041,0x005A,32},{0x00C0,0x00D6,32},{0x00D8,0x00DE,32},{0x0100,0x0136,0},{0x0139,0x0147,0},{0x014A,0x0176,0},{0x0178,0x0178,-121},
	{0x0179,0x017D,0},{0x0181,0x0181,210},{0x0182,0x0184,0},{0x0186,0x0186,206},{0x0187,0x0187,0},{0x018A,0x018A,205},{0x018B,0x018B,0},
	{0x018E,0x018F,202},{0x0190,0x0190,203},{0x0191,0x0191,0},{0x0193,0x0193,205},{0x0194,0x0194,207},{0x0196,0x0196,211},{0x0197,0x0197,209},
	{0x0198,0x0198,0},{0x019C,0x019C,211},{0x019D,0x019D,213},{0x019F,0x019F,214},{0x01A0,0x01A4,0},{0x01A7,0x01A7,0},{0x01A9,0x01A9,218},
	{0x01AC,0x01AC,0},{0x01AE,0x01AE,218},{0x01AF,0x01AF,0},{0x01B1,0x01B2,217},{0x01B3,0x01B5,0},{0x01B7,0x01B7,219},{0x01B8,0x01B8,0},
	{0x01BC,0x01BC,0},{0x01C4,0x01C4,2},{0x01C7,0x01C7,2},{0x01CA,0x01CA,2},{0x01CD,0x01DB,0},{0x01DE,0x01EE,0},{0x01F1,0x01F1,2},
	{0x01F4,0x01F4,0},{0x01FA,0x0216,0},{0x0386,0x0386,38},{0x0388,0x038A,37},{0x038C,0x038C,64},{0x038E,0x038F,63},{0x0391,0x03A1,32},
	{0x03A3,0x03AB,32},{0x03E2,0x03EE,0},{0x0401,0x040C,80},{0x040E,0x040F,80},{0x0410,0x042F,32},{0x0460,0x0480,0},{0x0490,0x04BE,0},
	{0x04C1,0x04C3,0},{0x04C7,0x04C7,0},{0x04CB,0x04CB,0},{0x04D0,0x04EA,0},{0x04EE,0x04F4,0},{0x04F8,0x04F8,0},{0x0531,0x0556,48},
	{0x10A0,0x10C5,48},{0x1E00,0x1E94,0},{0x1EA0,0x1EF8,0},{0x1F08,0x1F0F,-8},{0x1F18,0x1F1D,-8},{0x1F28,0x1F2F,-8},{0x1F38,0x1F3F,-8},
	{0x1F48,0x1F4D,-8},{0x1F59,0x1F59,-8},{0x1F5B,0x1F5B,-8},{0x1F5D,0x1F5D,-8},{0x1F5F,0x1F5F,-8},{0x1F68,0x1F6F,-8},{0x1F88,0x1F8F,-8},
	{0x1F98,0x1F9F,-8},{0x1FA8,0x1FAF,-8},{0x1FB8,0x1FB9,-8},{0x1FD8,0x1FD9,-8},{0x1FE8,0x1FE9,-8},{0x24B6,0x24CF,26},{0xFF21,0xFF3A,32}
};
const txCharCase gxCharCaseToUpper[mxCharCaseToUpperCount] ICACHE_XS6RO_ATTR = {
	{0x0061,0x007A,-32},{0x00E0,0x00F6,-32},{0x00F8,0x00FE,-32},{0x00FF,0x00FF,121},{0x0101,0x0137,0},{0x013A,0x0148,0},{0x014B,0x0177,0},
	{0x017A,0x017E,0},{0x0183,0x0185,0},{0x0188,0x0188,0},{0x018C,0x018C,0},{0x0192,0x0192,0},{0x0199,0x0199,0},{0x01A1,0x01A5,0},
	{0x01A8,0x01A8,0},{0x01AD,0x01AD,0},{0x01B0,0x01B0,0},{0x01B4,0x01B6,0},{0x01B9,0x01B9,0},{0x01BD,0x01BD,0},{0x01C6,0x01C6,-2},
	{0x01C9,0x01C9,-2},{0x01CC,0x01CC,-2},{0x01CE,0x01DC,0},{0x01DF,0x01EF,0},{0x01F3,0x01F3,-2},{0x01F5,0x01F5,0},{0x01FB,0x0217,0},
	{0x0253,0x0253,-210},{0x0254,0x0254,-206},{0x0257,0x0257,-205},{0x0258,0x0259,-202},{0x025B,0x025B,-203},{0x0260,0x0260,-205},{0x0263,0x0263,-207},
	{0x0268,0x0268,-209},{0x0269,0x0269,-211},{0x026F,0x026F,-211},{0x0272,0x0272,-213},{0x0275,0x0275,-214},{0x0283,0x0283,-218},{0x0288,0x0288,-218},
	{0x028A,0x028B,-217},{0x0292,0x0292,-219},{0x03AC,0x03AC,-38},{0x03AD,0x03AF,-37},{0x03B1,0x03C1,-32},{0x03C3,0x03CB,-32},{0x03CC,0x03CC,-64},
	{0x03CD,0x03CE,-63},{0x03E3,0x03EF,0},{0x0430,0x044F,-32},{0x0451,0x045C,-80},{0x045E,0x045F,-80},{0x0461,0x0481,0},{0x0491,0x04BF,0},
	{0x04C2,0x04C4,0},{0x04C8,0x04C8,0},{0x04CC,0x04CC,0},{0x04D1,0x04EB,0},{0x04EF,0x04F5,0},{0x04F9,0x04F9,0},{0x0561,0x0586,-48},
	{0x10D0,0x10F5,-48},{0x1E01,0x1E95,0},{0x1EA1,0x1EF9,0},{0x1F00,0x1F07,8},{0x1F10,0x1F15,8},{0x1F20,0x1F27,8},{0x1F30,0x1F37,8},
	{0x1F40,0x1F45,8},{0x1F51,0x1F51,8},{0x1F53,0x1F53,8},{0x1F55,0x1F55,8},{0x1F57,0x1F57,8},{0x1F60,0x1F67,8},{0x1F80,0x1F87,8},
	{0x1F90,0x1F97,8},{0x1FA0,0x1FA7,8},{0x1FB0,0x1FB1,8},{0x1FD0,0x1FD1,8},{0x1FE0,0x1FE1,8},{0x24D0,0x24E9,-26},{0xFF41,0xFF5A,-32}
};

void fxDeleteScript(txScript* script)
{
	if (script) {
		if (script->symbolsBuffer)
			c_free(script->symbolsBuffer);
		if (script->hostsBuffer)
			c_free(script->hostsBuffer);
		if (script->codeBuffer)
			c_free(script->codeBuffer);
		c_free(script);
	}
}

txBoolean fxIsIdentifier(txString string)
{
	txString p = string;
	char c = *p++;
	if (!fxIsIdentifierFirst(c))
		return 0;
	while ((c = *p++)) {
		if (!fxIsIdentifierNext(c))
			return 0;
	}
	return 1;
}

txBoolean fxIsIdentifierFirst(txU4 c)
{
	return ((('A' <= c) && (c <= 'Z')) || (('a' <= c) && (c <= 'z')) || (c == '$') || (c == '_') || ((c > 128) && !fxIsSpace(c) && (c != 0x0000180E))) ? 1 : 0;
}

txBoolean fxIsIdentifierNext(txU4 c)
{
	return ((('0' <= c) && (c <= '9')) || (('A' <= c) && (c <= 'Z')) || (('a' <= c) && (c <= 'z')) || (c == '$') || (c == '_') || ((c > 128) && !fxIsSpace(c) && (c != 0x0000180E))) ? 1 : 0;
}

txU1* fsX2UTF8(txU4 c, txU1* p, txU4 theSize)
{
	txU4 i;
	const txUTF8Sequence *aSequence;
	txS4 aShift;
	
	i = 0;
	for (aSequence = gxUTF8Sequences; aSequence->size; aSequence++)
		if (c <= aSequence->lmask)
			break;
	if (aSequence->size == 0)
		return p;
	i += aSequence->size;
	if (i < theSize) {
		aShift = aSequence->shift;
		*p++ = (unsigned char)(aSequence->cval | (c >> aShift));
		while (aShift > 0) {
			aShift -= 6;
			*p++ = (unsigned char)(0x80 | ((c >> aShift) & 0x3F));
		}
	}
	else {
		*p = 0;
		p += theSize;
	}
	return p;
}

txBoolean fxIsSpace(txU4 c)
{
	static const txU4 spaces[27] ICACHE_RODATA_ATTR = {
		0x00000009,
        0x0000000A,
        0x0000000B,
        0x0000000C,
        0x0000000D,
		0x00000020,
		0x000000A0,
		0x00001680,
		0x00002000,
		0x00002001,
		0x00002002,
		0x00002003,
		0x00002004,
		0x00002005,
		0x00002006,
		0x00002007,
		0x00002008,
		0x00002009,
		0x0000200A,
		0x00002028,
		0x00002029,
		0x0000202F,
		0x0000205F,
		0x00003000,
		0x0000FEFF,
		0xFFFFFFFF,
		0x00000000,
	};
	const txU4 *p = spaces;
	txU4 s;
	while ((s = *p++)) {
		if (c < s)
			return 0;
		if (c == s)
			return 1;
	}
	return 0;
}

txString fxSkipSpaces(txString string) 
{
	const txUTF8Sequence *sequence;
	txU1* p = (txU1*)string;
	txU1* q = p;
	txU4 c;
	txS4 size;
	while ((c = c_read8(q))) {
		q++;
		for (sequence = gxUTF8Sequences; sequence->size; sequence++) {
			if ((c & sequence->cmask) == sequence->cval)
				break;
		}
		size = sequence->size - 1;
		while (size > 0) {
			size--;
			c = (c << 6) | (c_read8(q) & 0x3F);
			q++;
		}
		c &= sequence->lmask;
		if (fxIsSpace(c))
			 p = q;
		else
			break;
	}
	return (txString)p;
}

txU4 fxUTF8Character(txString theString, txS4* theSize)
{
	txU1* p = (txU1*)theString;
	txU4 c = *p;
	txS4 size;
	if (c & 0x80) {
		const txUTF8Sequence *sequence;
		for (sequence = gxUTF8Sequences; sequence->size; sequence++) {
			if ((c & sequence->cmask) == sequence->cval)
				break;
		}
		size = sequence->size;
        if (theSize)
            *theSize = size;
		if (size == 0) {
			c = 0;
		}
		else {
			size--;
			while (size) {
				size--;
				c = (c << 6) | (*p++ & 0x3F);
			}
			c &= sequence->lmask;
		}
	}
    else if (theSize)
        *theSize = 1;
	return c;
}

txInteger fxUnicodeCharacter(txString theString)
{
	txU1* aString = (txU1*)theString;
	txU4 aResult = c_read8(aString++);
	const txUTF8Sequence *aSequence;
	txInteger aSize;

	for (aSequence = gxUTF8Sequences; aSequence->size; aSequence++) {
		if ((aResult & aSequence->cmask) == aSequence->cval)
			break;
	}
	aSize = aSequence->size - 1;
	while (aSize > 0) {
		aSize--;
		aResult = (aResult << 6) | (c_read8(aString++) & 0x3F);
	}
	aResult &= aSequence->lmask;
	return (txInteger)aResult;
}

txInteger fxUnicodeLength(txString theString)
{
	txU1* p = (txU1*)theString;
	txU1 c;
	txInteger anIndex = 0;
	
	while ((c = c_read8(p++))) {
		if ((c & 0xC0) != 0x80)
			anIndex++;
	}
	return anIndex;
}

txInteger fxUnicodeToUTF8Offset(txString theString, txInteger theOffset)
{
	txU1* p = (txU1*)theString;
	txU1 c;
	txInteger unicodeOffset = 0;
	txInteger utf8Offset = 0;
	
	while ((c = c_read8(p++))) {
		if ((c & 0xC0) != 0x80) {
			if (unicodeOffset == theOffset)
				return utf8Offset;
			unicodeOffset++;
		}
		utf8Offset++;
	}
	if (unicodeOffset == theOffset)
		return utf8Offset;
	else
		return -1;
}

txInteger fxUTF8ToUnicodeOffset(txString theString, txInteger theOffset)
{
	txU1* p = (txU1*)theString;
	txU1 c;
	txInteger unicodeOffset = 0;
	txInteger utf8Offset = 0;
	
	while ((c = c_read8(p++))) {
		if ((c & 0xC0) != 0x80) {
			if (utf8Offset == theOffset)
				return unicodeOffset;
			unicodeOffset++;
		}
		utf8Offset++;
	}
	if (utf8Offset == theOffset)
		return unicodeOffset;
	else
		return -1;
}

txFlag fxIntegerToIndex(void* dtoa, txInteger theInteger, txIndex* theIndex)
{
	if (0 <= theInteger) {
		*theIndex = (txIndex)theInteger;
		return 1;
	}
	return 0;
}

txFlag fxNumberToIndex(void* dtoa, txNumber number, txIndex* theIndex)
{
	txIndex integer = (txIndex)number;
	txNumber check = integer;
	if ((number == check) && (integer < 4294967295u)) {
		*theIndex = integer;
		return 1;
	}
	return 0;
}

txFlag fxStringToIndex(void* dtoa, txString theString, txIndex* theIndex)
{
	char buffer[256], c;
	txNumber number;
	txIndex integer;
	txNumber check;

	c = c_read8(theString);
	if (('+' != c) && ('-' != c) && ('.' != c) && !(('0' <= c) && ('9' >= c)))
		return 0;
	number = fxStringToNumber(dtoa, theString, 1);
	integer = (txIndex)number;
	check = integer;
	if ((number == check) && (integer < 4294967295u)) {
		fxNumberToString(dtoa, number, buffer, sizeof(buffer), 0, 0);
		if (!c_strcmp(theString, buffer)) {
			*theIndex = integer;
			return 1;
		}
	}
	return 0;
}

const txString gxIDStrings[XS_ID_COUNT] = {
	"@",
	"Symbol.hasInstance",
	"Symbol.isConcatSpreadable",
	"Symbol.iterator",
	"Symbol.match",
	"Symbol.replace",
	"Symbol.search",
	"Symbol.species",
	"Symbol.split",
	"Symbol.toPrimitive",
	"Symbol.toStringTag",
	"Symbol.unscopables",
	"Array",
	"ArrayBuffer",
	"AsyncFunction",
	"Atomics",
	"Boolean",
	"Chunk",
	"DataView",
	"Date",
	"Error",
	"EvalError",
	"Float32Array",
	"Float64Array",
	"Function",
	"Infinity",
	"Int16Array",
	"Int32Array",
	"Int8Array",
	"JSON",
	"Map",
	"Math",
	"NaN",
	"Number",
	"Object",
	"Promise",
	"Proxy",
	"RangeError",
	"ReferenceError",
	"Reflect",
	"RegExp",
	"Set",
	"SharedArrayBuffer",
	"String",
	"Symbol",
	"SyntaxError",
	"TypeError",
	"URIError",
	"Uint16Array",
	"Uint32Array",
	"Uint8Array",
	"Uint8ClampedArray",
	"WeakMap",
	"WeakSet",
	"decodeURI",
	"decodeURIComponent",
	"encodeURI",
	"encodeURIComponent",
	"escape",
	"eval",
	"isFinite",
	"isNaN",
	"parseFloat",
	"parseInt",
	"require",
	"trace",
	"undefined",
	"unescape",
	"__proto__",
	"BYTES_PER_ELEMENT",
	"E",
	"EPSILON",
	"Generator",
	"GeneratorFunction",
	"LN10",
	"LN2",
	"LOG10E",
	"LOG2E",
	"MAX_SAFE_INTEGER",
	"MAX_VALUE",
	"MIN_SAFE_INTEGER",
	"MIN_VALUE",
	"NEGATIVE_INFINITY",
	"PI",
	"POSITIVE_INFINITY",
	"SQRT1_2",
	"SQRT2",
	"UTC",
	"abs",
	"acos",
	"acosh",
	"add",
	"aliases",
	"all",
	"and",
	"append",
	"apply",
	"arguments",
	"asin",
	"asinh",
	"assign",
	"atan",
	"atanh",
	"atan2",
	"bind",
	"boundArguments",
	"boundFunction",
	"boundThis",
	"buffer",
	"busy",
	"byteLength",
	"byteOffset",
	"call",
	"callee",
	"caller",
	"catch",
	"cbrt",
	"ceil",
	"charAt",
	"charCodeAt",
	"chunk",
	"chunkify",
	"clear",
	"closure",
	"clz32",
	"codePointAt",
	"compare",
	"compareExchange",
	"compile",
	"concat",
	"configurable",
	"console",
	"construct",
	"constructor",
	"copyWithin",
	"cos",
	"cosh",
	"count",
	"create",
	"default",
	"defineProperties",
	"defineProperty",
	"delete",
	"deleteProperty",
	"done",
	"dotAll",
	"eachDown",
	"eachUp",
	"endsWith",
	"entries",
	"enumerable",
	"enumerate",
	"every",
	"exchange",
	"exec",
	"exp",
	"expm1",
	"exports",
	"fill",
	"filter",
	"find",
	"findIndex",
	"flags",
	"floor",
	"for",
	"forEach",
	"free",
	"freeze",
	"from",
	"fromArrayBuffer",
	"fromCharCode",
	"fromCodePoint",
	"fromString",
	"fround",
	"function",
	"get",
	"getDate",
	"getDay",
	"getFloat32",
	"getFloat64",
	"getFullYear",
	"getHours",
	"getInt16",
	"getInt32",
	"getInt8",
	"getMilliseconds",
	"getMinutes",
	"getMonth",
	"getOwnPropertyDescriptor",
	"getOwnPropertyDescriptors",
	"getOwnPropertyNames",
	"getOwnPropertySymbols",
	"getPrototypeOf",
	"getSeconds",
	"getTime",
	"getTimezoneOffset",
	"getUTCDate",
	"getUTCDay",
	"getUTCFullYear",
	"getUTCHours",
	"getUTCMilliseconds",
	"getUTCMinutes",
	"getUTCMonth",
	"getUTCSeconds",
	"getUint16",
	"getUint32",
	"getUint8",
	"getUint8Clamped",
	"getYear",
	"global",
	"has",
	"hasInstance",
	"hasOwnProperty",
	"hypot",
	"id",
	"ignoreCase",
	"import",
	"imul",
	"includes",
	"index",
	"indexOf",
	"input",
	"is",
	"isArray",
	"isConcatSpreadable",
	"isExtensible",
	"isFrozen",
	"isInteger",
	"isLockFree",
	"isPrototypeOf",
	"isSafeInteger",
	"isSealed",
	"isView",
	"iterable",
	"iterator",
	"join",
	"keyFor",
	"keys",
	"lastIndex",
	"lastIndexOf",
	"length",
	"line",
	"load",
	"local",
	"localeCompare",
	"log",
	"log1p",
	"log10",
	"log2",
	"map",
	"match",
	"max",
	"message",
	"min",
	"multiline",
	"name",
	"next",
	"normalize",
	"now",
	"of",
	"or",
	"ownKeys",
	"padEnd",
	"padStart",
	"parse",
	"path",
	"peek",
	"poke",
	"pop",
	"pow",
	"preventExtensions",
	"propertyIsEnumerable",
	"propertyIsScriptable",
	"prototype",
	"proxy",
	"push",
	"race",
	"random",
	"raw",
	"reduce",
	"reduceRight",
	"reject",
	"repeat",
	"replace",
	"resolve",
	"result",
	"return",
	"reverse",
	"revocable",
	"revoke",
	"round",
	"seal",
	"search",
	"serialize",
	"set",
	"setDate",
	"setFloat32",
	"setFloat64",
	"setFullYear",
	"setHours",
	"setInt16",
	"setInt32",
	"setInt8",
	"setMilliseconds",
	"setMinutes",
	"setMonth",
	"setPrototypeOf",
	"setSeconds",
	"setTime",
	"setUTCDate",
	"setUTCFullYear",
	"setUTCHours",
	"setUTCMilliseconds",
	"setUTCMinutes",
	"setUTCMonth",
	"setUTCSeconds",
	"setUint16",
	"setUint32",
	"setUint8",
	"setUint8Clamped",
	"setYear",
	"shift",
	"sign",
	"sin",
	"sinh",
	"size",
	"slice",
	"some",
	"sort",
	"source",
	"species",
	"splice",
	"split",
	"sqrt",
	"startsWith",
	"sticky",
	"store",
	"stringify",
	"sub",
	"subarray",
	"substr",
	"substring",
	"tan",
	"tanh",
	"test",
	"then",
	"this",
	"throw",
	"toDateString",
	"toExponential",
	"toFixed",
	"toGMTString",
	"toISOString",
	"toJSON",
	"toLocaleDateString",
	"toLocaleLowerCase",
	"toLocaleString",
	"toLocaleTimeString",
	"toLocaleUpperCase",
	"toLowerCase",
	"toPrecision",
	"toPrimitive",
	"toString",
	"toStringTag",
	"toTimeString",
	"toUTCString",
	"toUpperCase",
	"transfers",
	"trim",
	"trunc",
	"unicode",
	"unscopables",
	"unshift",
	"uri",
	"value",
	"valueOf",
	"values",
	"wait",
	"wake",
	"weak",
	"writable",
	"xor",
	"__dirname",
	"__filename",
	"new.target",
	"TypedArray",
	"cache",
};
