//File: preprocessor.h
//Author: 张子辰
// 本文件位于共有领域。
#ifndef ZZCPP_ECHO

#define ZZCPP_ECHO(...) __VA_ARGS__
#define ZZCPP_COMMA(...) ,
#define ZZCPP_EMPTY(...)
#define ZZCPP_FALSE(...) 0
#define ZZCPP_TRUE(...) 1

//延迟拼接
#define ZZCPP_CONCAT(x,y) ZZCPP_CONCAT_IMPL(x,y)
#define ZZCPP_CONCAT_IMPL(x,y) x##y

//元组解包
#define ZZCPP_UNPACK(x) ZZCPP_ECHO x

//获取参数
#define ZZCPP_GET(i,...) ZZCPP_CONCAT(ZZCPP_GET_IMPL,i) (__VA_ARGS__)
#define ZZCPP_GET_0(arg0,...) arg0
#define ZZCPP_GET_1(arg0,arg1,...) arg1
#define ZZCPP_GET_2(arg0,arg1,arg2,...) arg2
#define ZZCPP_GET_3(arg0,arg1,arg2,arg3,...) arg3
#define ZZCPP_GET_4(arg0,arg1,arg2,arg3,arg4,...) arg4
#define ZZCPP_GET_5(arg0,arg1,arg2,arg3,arg4,arg5,...) arg5
#define ZZCPP_GET_6(arg0,arg1,arg2,arg3,arg4,arg5,arg6,...) arg6
#define ZZCPP_GET_7(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,...) arg7
#define ZZCPP_GET_8(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,...) arg8
#define ZZCPP_GET_9(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,...) arg9
#define ZZCPP_GET_10(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,...) arg10
#define ZZCPP_GET_11(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,...) arg11
#define ZZCPP_GET_12(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12,...) arg12
#define ZZCPP_GET_13(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12,arg13,...) arg13
#define ZZCPP_GET_14(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12,arg13,arg14,...) arg14
#define ZZCPP_GET_15(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12,arg13,arg14,arg15,...) arg15
#define ZZCPP_GET_16(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12,arg13,arg14,arg15,arg16,...) arg16
#define ZZCPP_GET_17(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12,arg13,arg14,arg15,arg16,arg17,...) arg17
#define ZZCPP_GET_18(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12,arg13,arg14,arg15,arg16,arg17,arg18,...) arg18
#define ZZCPP_GET_19(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12,arg13,arg14,arg15,arg16,arg17,arg18,arg19,...) arg19
#define ZZCPP_GET_20(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12,arg13,arg14,arg15,arg16,arg17,arg18,arg19,arg20,...) arg20
#define ZZCPP_GET_21(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12,arg13,arg14,arg15,arg16,arg17,arg18,arg19,arg20,arg21,...) arg21
#define ZZCPP_GET_22(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12,arg13,arg14,arg15,arg16,arg17,arg18,arg19,arg20,arg21,arg22,...) arg22
#define ZZCPP_GET_23(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12,arg13,arg14,arg15,arg16,arg17,arg18,arg19,arg20,arg21,arg22,arg23,...) arg23
#define ZZCPP_GET_24(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12,arg13,arg14,arg15,arg16,arg17,arg18,arg19,arg20,arg21,arg22,arg23,arg24,...) arg24
#define ZZCPP_GET_25(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12,arg13,arg14,arg15,arg16,arg17,arg18,arg19,arg20,arg21,arg22,arg23,arg24,arg25,...) arg25
#define ZZCPP_GET_26(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12,arg13,arg14,arg15,arg16,arg17,arg18,arg19,arg20,arg21,arg22,arg23,arg24,arg25,arg26,...) arg26
#define ZZCPP_GET_27(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12,arg13,arg14,arg15,arg16,arg17,arg18,arg19,arg20,arg21,arg22,arg23,arg24,arg25,arg26,arg27,...) arg27
#define ZZCPP_GET_28(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12,arg13,arg14,arg15,arg16,arg17,arg18,arg19,arg20,arg21,arg22,arg23,arg24,arg25,arg26,arg27,arg28,...) arg28
#define ZZCPP_GET_29(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12,arg13,arg14,arg15,arg16,arg17,arg18,arg19,arg20,arg21,arg22,arg23,arg24,arg25,arg26,arg27,arg28,arg29,...) arg29
#define ZZCPP_GET_30(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12,arg13,arg14,arg15,arg16,arg17,arg18,arg19,arg20,arg21,arg22,arg23,arg24,arg25,arg26,arg27,arg28,arg29,arg30,...) arg30
#define ZZCPP_GET_31(arg0,arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12,arg13,arg14,arg15,arg16,arg17,arg18,arg19,arg20,arg21,arg22,arg23,arg24,arg25,arg26,arg27,arg28,arg29,arg30,arg31,...) arg31

//逻辑非
#define ZZCPP_NOT(x) ZZCPP_CONCAT(ZZCPP_NOT_IMPL,x)
#define ZZCPP_NOT_IMPL0 1
#define ZZCPP_NOT_IMPL1 0

//逻辑或
#define ZZCPP_OR(x,y) ZZCPP_CONCAT(ZZCPP_OR_IMPL,ZZCPP_CONCAT(x,y))
#define ZZCPP_OR_IMPL00 0
#define ZZCPP_OR_IMPL01 1
#define ZZCPP_OR_IMPL10 1
#define ZZCPP_OR_IMPL11 1

//逻辑与
#define ZZCPP_AND(x,y) ZZCPP_NOT(ZZCPP_OR(ZZCPP_NOT(x),ZZCPP_NOT(y)))

//逻辑异或
#define ZZCPP_XOR(x,y) ZZCPP_CONCAT(ZZCPP_XOR_IMPL,ZZCPP_CONCAT(x,y))
#define ZZCPP_XOR_IMPL00 1
#define ZZCPP_XOR_IMPL01 0
#define ZZCPP_XOR_IMPL10 0
#define ZZCPP_XOR_IMPL11 1

#define ZZCPP_BOOL(x) ZZCPP_CONCAT(ZZCPP_BOOL_IMPL,x)
#define ZZCPP_BOOL_IMPL0 0
#define ZZCPP_BOOL_IMPL1 1
#define ZZCPP_BOOL_IMPL2 1
#define ZZCPP_BOOL_IMPL3 1
#define ZZCPP_BOOL_IMPL4 1
#define ZZCPP_BOOL_IMPL5 1
#define ZZCPP_BOOL_IMPL6 1
#define ZZCPP_BOOL_IMPL7 1
#define ZZCPP_BOOL_IMPL8 1
#define ZZCPP_BOOL_IMPL9 1
#define ZZCPP_BOOL_IMPL10 1
#define ZZCPP_BOOL_IMPL11 1
#define ZZCPP_BOOL_IMPL12 1
#define ZZCPP_BOOL_IMPL13 1
#define ZZCPP_BOOL_IMPL14 1
#define ZZCPP_BOOL_IMPL15 1
#define ZZCPP_BOOL_IMPL16 1
#define ZZCPP_BOOL_IMPL17 1
#define ZZCPP_BOOL_IMPL18 1
#define ZZCPP_BOOL_IMPL19 1
#define ZZCPP_BOOL_IMPL20 1
#define ZZCPP_BOOL_IMPL21 1
#define ZZCPP_BOOL_IMPL22 1
#define ZZCPP_BOOL_IMPL23 1
#define ZZCPP_BOOL_IMPL24 1
#define ZZCPP_BOOL_IMPL25 1
#define ZZCPP_BOOL_IMPL26 1
#define ZZCPP_BOOL_IMPL27 1
#define ZZCPP_BOOL_IMPL28 1
#define ZZCPP_BOOL_IMPL29 1
#define ZZCPP_BOOL_IMPL30 1
#define ZZCPP_BOOL_IMPL31 1

//自增
#define ZZCPP_INC(x) ZZCPP_CONCAT(ZZCPP_INC_IMPL,x)
#define ZZCPP_INC_IMPL0 1
#define ZZCPP_INC_IMPL1 2
#define ZZCPP_INC_IMPL2 3
#define ZZCPP_INC_IMPL3 4
#define ZZCPP_INC_IMPL4 5
#define ZZCPP_INC_IMPL5 6
#define ZZCPP_INC_IMPL6 7
#define ZZCPP_INC_IMPL7 8
#define ZZCPP_INC_IMPL8 9
#define ZZCPP_INC_IMPL9 10
#define ZZCPP_INC_IMPL10 11
#define ZZCPP_INC_IMPL11 12
#define ZZCPP_INC_IMPL12 13
#define ZZCPP_INC_IMPL13 14
#define ZZCPP_INC_IMPL14 15
#define ZZCPP_INC_IMPL15 16
#define ZZCPP_INC_IMPL16 17
#define ZZCPP_INC_IMPL17 18
#define ZZCPP_INC_IMPL18 19
#define ZZCPP_INC_IMPL19 20
#define ZZCPP_INC_IMPL20 21
#define ZZCPP_INC_IMPL21 22
#define ZZCPP_INC_IMPL22 23
#define ZZCPP_INC_IMPL23 24
#define ZZCPP_INC_IMPL24 25
#define ZZCPP_INC_IMPL25 26
#define ZZCPP_INC_IMPL26 27
#define ZZCPP_INC_IMPL27 28
#define ZZCPP_INC_IMPL28 29
#define ZZCPP_INC_IMPL29 30
#define ZZCPP_INC_IMPL30 31

//自减
#define ZZCPP_DEC(x) ZZCPP_CONCAT(ZZCPP_DEC_IMPL,x)
#define ZZCPP_DEC_IMPL1 0
#define ZZCPP_DEC_IMPL2 1
#define ZZCPP_DEC_IMPL3 2
#define ZZCPP_DEC_IMPL4 3
#define ZZCPP_DEC_IMPL5 4
#define ZZCPP_DEC_IMPL6 5
#define ZZCPP_DEC_IMPL7 6
#define ZZCPP_DEC_IMPL8 7
#define ZZCPP_DEC_IMPL9 8
#define ZZCPP_DEC_IMPL10 9
#define ZZCPP_DEC_IMPL11 10
#define ZZCPP_DEC_IMPL12 11
#define ZZCPP_DEC_IMPL13 12
#define ZZCPP_DEC_IMPL14 13
#define ZZCPP_DEC_IMPL15 14
#define ZZCPP_DEC_IMPL16 15
#define ZZCPP_DEC_IMPL17 16
#define ZZCPP_DEC_IMPL18 17
#define ZZCPP_DEC_IMPL19 18
#define ZZCPP_DEC_IMPL20 19
#define ZZCPP_DEC_IMPL21 20
#define ZZCPP_DEC_IMPL22 21
#define ZZCPP_DEC_IMPL23 22
#define ZZCPP_DEC_IMPL24 23
#define ZZCPP_DEC_IMPL25 24
#define ZZCPP_DEC_IMPL26 25
#define ZZCPP_DEC_IMPL27 26
#define ZZCPP_DEC_IMPL28 27
#define ZZCPP_DEC_IMPL29 28
#define ZZCPP_DEC_IMPL30 29
#define ZZCPP_DEC_IMPL31 30

//选择语句
#define ZZCPP_IF(condition,then,else)\
	ZZCPP_CONCAT(ZZCPP_IF_IMPL,condition) (then,else)
#define ZZCPP_IF_IMPL0(then,else) else
#define ZZCPP_IF_IMPL1(then,else) then

//获取参数的数量
#define ZZCPP_COUNT_NE(...) ZZCPP_GET_31(__VA_ARGS__,31,30,29,28,27,26,\
	25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0)
#define ZZCPP_COUNT(...) ZZCPP_IF(ZZCPP_IS_EMPTY(__VA_ARGS__),\
	ZZCPP_FALSE,ZZCPP_COUNT_NE) (__VA_ARGS__)

//判断参数是否为元组
#define ZZCPP_IS_TUPLE0(x) ZZCPP_IS_TUPLE0_IMPL(ZZCPP_COMMA x)
#define ZZCPP_IS_TUPLE0_IMPL(...) ZZCPP_GET_2(__VA_ARGS__,1,0)
#define ZZCPP_IS_TUPLE(...) ZZCPP_IS_EMPTY(ZZCPP_EMPTY __VA_ARGS__)

//选择性的元组解包
#define ZZCPP_UNPACK_OPT(x)\
	ZZCPP_IF(ZZCPP_IS_TUPLE(x),ZZCPP_UNPACK,ZZCPP_ECHO) (x)

//判断是否为空

#define ZZCPP_IS_EMPTY(...)\
	ZZCPP_IF(ZZCPP_OR(ZZCPP_BOOL(ZZCPP_DEC(ZZCPP_COUNT_NE(__VA_ARGS__))),\
	ZZCPP_BOOL(ZZCPP_DEC(ZZCPP_COUNT_NE(__VA_ARGS__())))),\
	ZZCPP_FALSE,ZZCPP_IS_EMPTY_IMPL) (__VA_ARGS__)
#define ZZCPP_IS_EMPTY_IMPL(x)\
ZZCPP_AND(ZZCPP_NOT(ZZCPP_IS_TUPLE0(x)),\
ZZCPP_IS_TUPLE0(x()))

/*
#define ZZCPP_IS_EMPTY(...) ZZCPP_IS_EMPTY_IMPL(__VA_ARGS__)
#define ZZCPP_IS_EMPTY_IMPL(...) ZZCPP_GET_31(,##__VA_ARGS__,0,0,0,0,0,0,0,\
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1)
*/
//或
//#define ZZCPP_IS_EMPTY(...) ZZCPP_GET_2(__VA_OPT__(,),0,1)

//FOR_EACH
#define ZZCPP_FOR_EACH_E(command,separator,arg0,...)\
	command(arg0)

#define ZZCPP_FOR_EACH(command,separator,arg0,...)\
	ZZCPP_IF(ZZCPP_IS_EMPTY(__VA_ARGS__),\
	ZZCPP_FOR_EACH_E,ZZCPP_FOR_EACH_NE)\
	(command,separator,arg0,__VA_ARGS__)
#define ZZCPP_FOR_EACH_NE(command,separator,arg0,...)\
	command(arg0) ZZCPP_UNPACK_OPT(separator)\
	ZZCPP_FOR_EACH1(command,separator,__VA_ARGS__)

#define ZZCPP_FOR_EACH1(command,separator,arg0,...)\
	ZZCPP_IF(ZZCPP_IS_EMPTY(__VA_ARGS__),\
	ZZCPP_FOR_EACH_E,ZZCPP_FOR_EACH_NE1)\
	(command,separator,arg0,__VA_ARGS__)
#define ZZCPP_FOR_EACH_NE1(command,separator,arg0,...)\
	command(arg0) ZZCPP_UNPACK_OPT(separator)\
	ZZCPP_FOR_EACH2(command,separator,__VA_ARGS__)

#define ZZCPP_FOR_EACH2(command,separator,arg0,...)\
	ZZCPP_IF(ZZCPP_IS_EMPTY(__VA_ARGS__),\
	ZZCPP_FOR_EACH_E,ZZCPP_FOR_EACH_NE2)\
	(command,separator,arg0,__VA_ARGS__)
#define ZZCPP_FOR_EACH_NE2(command,separator,arg0,...)\
	command(arg0) ZZCPP_UNPACK_OPT(separator)\
	ZZCPP_FOR_EACH3(command,separator,__VA_ARGS__)

#define ZZCPP_FOR_EACH3(command,separator,arg0,...)\
	ZZCPP_IF(ZZCPP_IS_EMPTY(__VA_ARGS__),\
	ZZCPP_FOR_EACH_E,ZZCPP_FOR_EACH_NE3)\
	(command,separator,arg0,__VA_ARGS__)
#define ZZCPP_FOR_EACH_NE3(command,separator,arg0,...)\
	command(arg0) ZZCPP_UNPACK_OPT(separator)\
	ZZCPP_FOR_EACH4(command,separator,__VA_ARGS__)

#define ZZCPP_FOR_EACH4(command,separator,arg0,...)\
	ZZCPP_IF(ZZCPP_IS_EMPTY(__VA_ARGS__),\
	ZZCPP_FOR_EACH_E,ZZCPP_FOR_EACH_NE4)\
	(command,separator,arg0,__VA_ARGS__)
#define ZZCPP_FOR_EACH_NE4(command,separator,arg0,...)\
	command(arg0) ZZCPP_UNPACK_OPT(separator)\
	ZZCPP_FOR_EACH5(command,separator,__VA_ARGS__)

#define ZZCPP_FOR_EACH5(command,separator,arg0,...)\
	ZZCPP_IF(ZZCPP_IS_EMPTY(__VA_ARGS__),\
	ZZCPP_FOR_EACH_E,ZZCPP_FOR_EACH_NE5)\
	(command,separator,arg0,__VA_ARGS__)
#define ZZCPP_FOR_EACH_NE5(command,separator,arg0,...)\
	command(arg0) ZZCPP_UNPACK_OPT(separator)\
	ZZCPP_FOR_EACH6(command,separator,__VA_ARGS__)

#define ZZCPP_FOR_EACH6(command,separator,arg0,...)\
	ZZCPP_IF(ZZCPP_IS_EMPTY(__VA_ARGS__),\
	ZZCPP_FOR_EACH_E,ZZCPP_FOR_EACH_NE6)\
	(command,separator,arg0,__VA_ARGS__)
#define ZZCPP_FOR_EACH_NE6(command,separator,arg0,...)\
	command(arg0) ZZCPP_UNPACK_OPT(separator)\
	ZZCPP_FOR_EACH7(command,separator,__VA_ARGS__)

#define ZZCPP_FOR_EACH7(command,separator,arg0,...)\
	ZZCPP_IF(ZZCPP_IS_EMPTY(__VA_ARGS__),\
	ZZCPP_FOR_EACH_E,ZZCPP_FOR_EACH_NE7)\
	(command,separator,arg0,__VA_ARGS__)
#define ZZCPP_FOR_EACH_NE7(command,separator,arg0,...)\
	command(arg0) ZZCPP_UNPACK_OPT(separator)\
	ZZCPP_FOR_EACH8(command,separator,__VA_ARGS__)

#define ZZCPP_FOR_EACH8(command,separator,arg0,...)\
	ZZCPP_IF(ZZCPP_IS_EMPTY(__VA_ARGS__),\
	ZZCPP_FOR_EACH_E,ZZCPP_FOR_EACH_NE8)\
	(command,separator,arg0,__VA_ARGS__)
#define ZZCPP_FOR_EACH_NE8(command,separator,arg0,...)\
	command(arg0) ZZCPP_UNPACK_OPT(separator)\
	ZZCPP_FOR_EACH9(command,separator,__VA_ARGS__)

#define ZZCPP_FOR_EACH9(command,separator,arg0,...)\
	ZZCPP_IF(ZZCPP_IS_EMPTY(__VA_ARGS__),\
	ZZCPP_FOR_EACH_E,ZZCPP_FOR_EACH_NE9)\
	(command,separator,arg0,__VA_ARGS__)
#define ZZCPP_FOR_EACH_NE9(command,separator,arg0,...)\
	command(arg0) ZZCPP_UNPACK_OPT(separator)\
	ZZCPP_FOR_EACH10(command,separator,__VA_ARGS__)

#define ZZCPP_FOR_EACH10(command,separator,arg0,...)\
	ZZCPP_IF(ZZCPP_IS_EMPTY(__VA_ARGS__),\
	ZZCPP_FOR_EACH_E,ZZCPP_FOR_EACH_NE10)\
	(command,separator,arg0,__VA_ARGS__)
#define ZZCPP_FOR_EACH_NE10(command,separator,arg0,...)\
	command(arg0) ZZCPP_UNPACK_OPT(separator)\
	ZZCPP_FOR_EACH11(command,separator,__VA_ARGS__)

#define ZZCPP_FOR_EACH11(command,separator,arg0,...)\
	ZZCPP_IF(ZZCPP_IS_EMPTY(__VA_ARGS__),\
	ZZCPP_FOR_EACH_E,ZZCPP_FOR_EACH_NE11)\
	(command,separator,arg0,__VA_ARGS__)
#define ZZCPP_FOR_EACH_NE11(command,separator,arg0,...)\
	command(arg0) ZZCPP_UNPACK_OPT(separator)\
	ZZCPP_FOR_EACH12(command,separator,__VA_ARGS__)

#define ZZCPP_FOR_EACH12(command,separator,arg0,...)\
	ZZCPP_IF(ZZCPP_IS_EMPTY(__VA_ARGS__),\
	ZZCPP_FOR_EACH_E,ZZCPP_FOR_EACH_NE12)\
	(command,separator,arg0,__VA_ARGS__)
#define ZZCPP_FOR_EACH_NE12(command,separator,arg0,...)\
	command(arg0) ZZCPP_UNPACK_OPT(separator)\
	ZZCPP_FOR_EACH13(command,separator,__VA_ARGS__)

#define ZZCPP_FOR_EACH13(command,separator,arg0,...)\
	ZZCPP_IF(ZZCPP_IS_EMPTY(__VA_ARGS__),\
	ZZCPP_FOR_EACH_E,ZZCPP_FOR_EACH_NE13)\
	(command,separator,arg0,__VA_ARGS__)
#define ZZCPP_FOR_EACH_NE13(command,separator,arg0,...)\
	command(arg0) ZZCPP_UNPACK_OPT(separator)\
	ZZCPP_FOR_EACH14(command,separator,__VA_ARGS__)

#define ZZCPP_FOR_EACH14(command,separator,arg0,...)\
	ZZCPP_IF(ZZCPP_IS_EMPTY(__VA_ARGS__),\
	ZZCPP_FOR_EACH_E,ZZCPP_FOR_EACH_NE14)\
	(command,separator,arg0,__VA_ARGS__)
#define ZZCPP_FOR_EACH_NE14(command,separator,arg0,...)\
	command(arg0) ZZCPP_UNPACK_OPT(separator)\
	ZZCPP_FOR_EACH15(command,separator,__VA_ARGS__)

#define ZZCPP_FOR_EACH15(command,separator,arg0,...)\
	ZZCPP_IF(ZZCPP_IS_EMPTY(__VA_ARGS__),\
	ZZCPP_FOR_EACH_E,ZZCPP_FOR_EACH_NE15)\
	(command,separator,arg0,__VA_ARGS__)
#define ZZCPP_FOR_EACH_NE15(command,separator,arg0,...)\
	command(arg0) ZZCPP_UNPACK_OPT(separator)\
	ZZCPP_FOR_EACH16(command,separator,__VA_ARGS__)

#define ZZCPP_FOR_EACH16(command,separator,arg0,...)\
	ZZCPP_IF(ZZCPP_IS_EMPTY(__VA_ARGS__),\
	ZZCPP_FOR_EACH_E,ZZCPP_FOR_EACH_NE16)\
	(command,separator,arg0,__VA_ARGS__)
#define ZZCPP_FOR_EACH_NE16(command,separator,arg0,...)\
	command(arg0) ZZCPP_UNPACK_OPT(separator)\
	ZZCPP_FOR_EACH17(command,separator,__VA_ARGS__)

#define ZZCPP_FOR_EACH17(command,separator,arg0,...)\
	ZZCPP_IF(ZZCPP_IS_EMPTY(__VA_ARGS__),\
	ZZCPP_FOR_EACH_E,ZZCPP_FOR_EACH_NE17)\
	(command,separator,arg0,__VA_ARGS__)
#define ZZCPP_FOR_EACH_NE17(command,separator,arg0,...)\
	command(arg0) ZZCPP_UNPACK_OPT(separator)\
	ZZCPP_FOR_EACH18(command,separator,__VA_ARGS__)

#define ZZCPP_FOR_EACH18(command,separator,arg0,...)\
	ZZCPP_IF(ZZCPP_IS_EMPTY(__VA_ARGS__),\
	ZZCPP_FOR_EACH_E,ZZCPP_FOR_EACH_NE18)\
	(command,separator,arg0,__VA_ARGS__)
#define ZZCPP_FOR_EACH_NE18(command,separator,arg0,...)\
	command(arg0) ZZCPP_UNPACK_OPT(separator)\
	ZZCPP_FOR_EACH19(command,separator,__VA_ARGS__)

#define ZZCPP_FOR_EACH19(command,separator,arg0,...)\
	ZZCPP_IF(ZZCPP_IS_EMPTY(__VA_ARGS__),\
	ZZCPP_FOR_EACH_E,ZZCPP_FOR_EACH_NE19)\
	(command,separator,arg0,__VA_ARGS__)
#define ZZCPP_FOR_EACH_NE19(command,separator,arg0,...)\
	command(arg0) ZZCPP_UNPACK_OPT(separator)\
	ZZCPP_FOR_EACH20(command,separator,__VA_ARGS__)

#define ZZCPP_FOR_EACH20(command,separator,arg0,...)\
	ZZCPP_IF(ZZCPP_IS_EMPTY(__VA_ARGS__),\
	ZZCPP_FOR_EACH_E,ZZCPP_FOR_EACH_NE20)\
	(command,separator,arg0,__VA_ARGS__)
#define ZZCPP_FOR_EACH_NE20(command,separator,arg0,...)\
	command(arg0) ZZCPP_UNPACK_OPT(separator)\
	ZZCPP_FOR_EACH21(command,separator,__VA_ARGS__)

#define ZZCPP_FOR_EACH21(command,separator,arg0,...)\
	ZZCPP_IF(ZZCPP_IS_EMPTY(__VA_ARGS__),\
	ZZCPP_FOR_EACH_E,ZZCPP_FOR_EACH_NE21)\
	(command,separator,arg0,__VA_ARGS__)
#define ZZCPP_FOR_EACH_NE21(command,separator,arg0,...)\
	command(arg0) ZZCPP_UNPACK_OPT(separator)\
	ZZCPP_FOR_EACH22(command,separator,__VA_ARGS__)

#define ZZCPP_FOR_EACH22(command,separator,arg0,...)\
	ZZCPP_IF(ZZCPP_IS_EMPTY(__VA_ARGS__),\
	ZZCPP_FOR_EACH_E,ZZCPP_FOR_EACH_NE22)\
	(command,separator,arg0,__VA_ARGS__)
#define ZZCPP_FOR_EACH_NE22(command,separator,arg0,...)\
	command(arg0) ZZCPP_UNPACK_OPT(separator)\
	ZZCPP_FOR_EACH23(command,separator,__VA_ARGS__)

#define ZZCPP_FOR_EACH23(command,separator,arg0,...)\
	ZZCPP_IF(ZZCPP_IS_EMPTY(__VA_ARGS__),\
	ZZCPP_FOR_EACH_E,ZZCPP_FOR_EACH_NE23)\
	(command,separator,arg0,__VA_ARGS__)
#define ZZCPP_FOR_EACH_NE23(command,separator,arg0,...)\
	command(arg0) ZZCPP_UNPACK_OPT(separator)\
	ZZCPP_FOR_EACH24(command,separator,__VA_ARGS__)

#define ZZCPP_FOR_EACH24(command,separator,arg0,...)\
	ZZCPP_IF(ZZCPP_IS_EMPTY(__VA_ARGS__),\
	ZZCPP_FOR_EACH_E,ZZCPP_FOR_EACH_NE24)\
	(command,separator,arg0,__VA_ARGS__)
#define ZZCPP_FOR_EACH_NE24(command,separator,arg0,...)\
	command(arg0) ZZCPP_UNPACK_OPT(separator)\
	ZZCPP_FOR_EACH25(command,separator,__VA_ARGS__)

#define ZZCPP_FOR_EACH25(command,separator,arg0,...)\
	ZZCPP_IF(ZZCPP_IS_EMPTY(__VA_ARGS__),\
	ZZCPP_FOR_EACH_E,ZZCPP_FOR_EACH_NE25)\
	(command,separator,arg0,__VA_ARGS__)
#define ZZCPP_FOR_EACH_NE25(command,separator,arg0,...)\
	command(arg0) ZZCPP_UNPACK_OPT(separator)\
	ZZCPP_FOR_EACH26(command,separator,__VA_ARGS__)

#define ZZCPP_FOR_EACH26(command,separator,arg0,...)\
	ZZCPP_IF(ZZCPP_IS_EMPTY(__VA_ARGS__),\
	ZZCPP_FOR_EACH_E,ZZCPP_FOR_EACH_NE26)\
	(command,separator,arg0,__VA_ARGS__)
#define ZZCPP_FOR_EACH_NE26(command,separator,arg0,...)\
	command(arg0) ZZCPP_UNPACK_OPT(separator)\
	ZZCPP_FOR_EACH27(command,separator,__VA_ARGS__)

#define ZZCPP_FOR_EACH27(command,separator,arg0,...)\
	ZZCPP_IF(ZZCPP_IS_EMPTY(__VA_ARGS__),\
	ZZCPP_FOR_EACH_E,ZZCPP_FOR_EACH_NE27)\
	(command,separator,arg0,__VA_ARGS__)
#define ZZCPP_FOR_EACH_NE27(command,separator,arg0,...)\
	command(arg0) ZZCPP_UNPACK_OPT(separator)\
	ZZCPP_FOR_EACH28(command,separator,__VA_ARGS__)

#define ZZCPP_FOR_EACH28(command,separator,arg0,...)\
	ZZCPP_IF(ZZCPP_IS_EMPTY(__VA_ARGS__),\
	ZZCPP_FOR_EACH_E,ZZCPP_FOR_EACH_NE28)\
	(command,separator,arg0,__VA_ARGS__)
#define ZZCPP_FOR_EACH_NE28(command,separator,arg0,...)\
	command(arg0) ZZCPP_UNPACK_OPT(separator)\
	ZZCPP_FOR_EACH29(command,separator,__VA_ARGS__)

#define ZZCPP_FOR_EACH29(command,separator,arg0,...)\
	ZZCPP_IF(ZZCPP_IS_EMPTY(__VA_ARGS__),\
	ZZCPP_FOR_EACH_E,ZZCPP_FOR_EACH_NE29)\
	(command,separator,arg0,__VA_ARGS__)
#define ZZCPP_FOR_EACH_NE29(command,separator,arg0,...)\
	command(arg0) ZZCPP_UNPACK_OPT(separator)\
	ZZCPP_FOR_EACH30(command,separator,__VA_ARGS__)

#define ZZCPP_FOR_EACH30(command,separator,arg0,...)\
	ZZCPP_IF(ZZCPP_IS_EMPTY(__VA_ARGS__),\
	ZZCPP_FOR_EACH_E,ZZCPP_FOR_EACH_NE30)\
	(command,separator,arg0,__VA_ARGS__)
#define ZZCPP_FOR_EACH_NE30(command,separator,arg0,...)\
	command(arg0) ZZCPP_UNPACK_OPT(separator)\
	ZZCPP_FOR_EACH31(command,separator,__VA_ARGS__)

#define ZZCPP_FOR_EACH31(command,separator,arg0,...)\
	ZZCPP_IF(ZZCPP_IS_EMPTY(__VA_ARGS__),\
	ZZCPP_FOR_EACH_E,ZZCPP_FOR_EACH_NE31)\
	(command,separator,arg0,__VA_ARGS__)
#define ZZCPP_FOR_EACH_NE31(command,separator,arg0,...)\
	command(arg0) ZZCPP_UNPACK_OPT(separator)\
	ZZCPP_FOR_EACH32(command,separator,__VA_ARGS__)

//WHILE
#define ZZCPP_WHILE_E(term_condition,command,last_command,...)\
	last_command(__VA_ARGS__)

#define ZZCPP_WHILE(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_E,ZZCPP_WHILE_NE)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_NE(term_condition,command,last_command,...)\
	ZZCPP_WHILE1(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE1(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_E,ZZCPP_WHILE_NE1)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_NE1(term_condition,command,last_command,...)\
	ZZCPP_WHILE2(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE2(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_E,ZZCPP_WHILE_NE2)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_NE2(term_condition,command,last_command,...)\
	ZZCPP_WHILE3(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE3(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_E,ZZCPP_WHILE_NE3)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_NE3(term_condition,command,last_command,...)\
	ZZCPP_WHILE4(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE4(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_E,ZZCPP_WHILE_NE4)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_NE4(term_condition,command,last_command,...)\
	ZZCPP_WHILE5(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE5(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_E,ZZCPP_WHILE_NE5)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_NE5(term_condition,command,last_command,...)\
	ZZCPP_WHILE6(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE6(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_E,ZZCPP_WHILE_NE6)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_NE6(term_condition,command,last_command,...)\
	ZZCPP_WHILE7(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE7(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_E,ZZCPP_WHILE_NE7)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_NE7(term_condition,command,last_command,...)\
	ZZCPP_WHILE8(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE8(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_E,ZZCPP_WHILE_NE8)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_NE8(term_condition,command,last_command,...)\
	ZZCPP_WHILE9(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE9(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_E,ZZCPP_WHILE_NE9)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_NE9(term_condition,command,last_command,...)\
	ZZCPP_WHILE10(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE10(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_E,ZZCPP_WHILE_NE10)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_NE10(term_condition,command,last_command,...)\
	ZZCPP_WHILE11(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE11(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_E,ZZCPP_WHILE_NE11)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_NE11(term_condition,command,last_command,...)\
	ZZCPP_WHILE12(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE12(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_E,ZZCPP_WHILE_NE12)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_NE12(term_condition,command,last_command,...)\
	ZZCPP_WHILE13(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE13(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_E,ZZCPP_WHILE_NE13)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_NE13(term_condition,command,last_command,...)\
	ZZCPP_WHILE14(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE14(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_E,ZZCPP_WHILE_NE14)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_NE14(term_condition,command,last_command,...)\
	ZZCPP_WHILE15(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE15(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_E,ZZCPP_WHILE_NE15)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_NE15(term_condition,command,last_command,...)\
	ZZCPP_WHILE16(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE16(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_E,ZZCPP_WHILE_NE16)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_NE16(term_condition,command,last_command,...)\
	ZZCPP_WHILE17(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE17(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_E,ZZCPP_WHILE_NE17)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_NE17(term_condition,command,last_command,...)\
	ZZCPP_WHILE18(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE18(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_E,ZZCPP_WHILE_NE18)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_NE18(term_condition,command,last_command,...)\
	ZZCPP_WHILE19(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE19(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_E,ZZCPP_WHILE_NE19)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_NE19(term_condition,command,last_command,...)\
	ZZCPP_WHILE20(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE20(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_E,ZZCPP_WHILE_NE20)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_NE20(term_condition,command,last_command,...)\
	ZZCPP_WHILE21(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE21(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_E,ZZCPP_WHILE_NE21)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_NE21(term_condition,command,last_command,...)\
	ZZCPP_WHILE22(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE22(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_E,ZZCPP_WHILE_NE22)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_NE22(term_condition,command,last_command,...)\
	ZZCPP_WHILE23(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE23(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_E,ZZCPP_WHILE_NE23)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_NE23(term_condition,command,last_command,...)\
	ZZCPP_WHILE24(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE24(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_E,ZZCPP_WHILE_NE24)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_NE24(term_condition,command,last_command,...)\
	ZZCPP_WHILE25(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE25(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_E,ZZCPP_WHILE_NE25)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_NE25(term_condition,command,last_command,...)\
	ZZCPP_WHILE26(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE26(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_E,ZZCPP_WHILE_NE26)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_NE26(term_condition,command,last_command,...)\
	ZZCPP_WHILE27(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE27(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_E,ZZCPP_WHILE_NE27)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_NE27(term_condition,command,last_command,...)\
	ZZCPP_WHILE28(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE28(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_E,ZZCPP_WHILE_NE28)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_NE28(term_condition,command,last_command,...)\
	ZZCPP_WHILE29(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE29(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_E,ZZCPP_WHILE_NE29)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_NE29(term_condition,command,last_command,...)\
	ZZCPP_WHILE30(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE30(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_E,ZZCPP_WHILE_NE30)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_NE30(term_condition,command,last_command,...)\
	ZZCPP_WHILE31(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE31(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_E,ZZCPP_WHILE_NE31)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_NE31(term_condition,command,last_command,...)\
	ZZCPP_WHILE32(term_condition,command,last_command,command(__VA_ARGS__))

//WHILE_II
#define ZZCPP_WHILE_II_E(term_condition,command,last_command,...)\
	last_command(__VA_ARGS__)

#define ZZCPP_WHILE_II(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_II_E,ZZCPP_WHILE_II_NE)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_II_NE(term_condition,command,last_command,...)\
	ZZCPP_WHILE_II1(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_II1(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_II_E,ZZCPP_WHILE_II_NE1)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_II_NE1(term_condition,command,last_command,...)\
	ZZCPP_WHILE_II2(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_II2(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_II_E,ZZCPP_WHILE_II_NE2)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_II_NE2(term_condition,command,last_command,...)\
	ZZCPP_WHILE_II3(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_II3(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_II_E,ZZCPP_WHILE_II_NE3)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_II_NE3(term_condition,command,last_command,...)\
	ZZCPP_WHILE_II4(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_II4(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_II_E,ZZCPP_WHILE_II_NE4)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_II_NE4(term_condition,command,last_command,...)\
	ZZCPP_WHILE_II5(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_II5(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_II_E,ZZCPP_WHILE_II_NE5)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_II_NE5(term_condition,command,last_command,...)\
	ZZCPP_WHILE_II6(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_II6(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_II_E,ZZCPP_WHILE_II_NE6)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_II_NE6(term_condition,command,last_command,...)\
	ZZCPP_WHILE_II7(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_II7(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_II_E,ZZCPP_WHILE_II_NE7)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_II_NE7(term_condition,command,last_command,...)\
	ZZCPP_WHILE_II8(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_II8(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_II_E,ZZCPP_WHILE_II_NE8)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_II_NE8(term_condition,command,last_command,...)\
	ZZCPP_WHILE_II9(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_II9(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_II_E,ZZCPP_WHILE_II_NE9)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_II_NE9(term_condition,command,last_command,...)\
	ZZCPP_WHILE_II10(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_II10(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_II_E,ZZCPP_WHILE_II_NE10)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_II_NE10(term_condition,command,last_command,...)\
	ZZCPP_WHILE_II11(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_II11(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_II_E,ZZCPP_WHILE_II_NE11)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_II_NE11(term_condition,command,last_command,...)\
	ZZCPP_WHILE_II12(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_II12(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_II_E,ZZCPP_WHILE_II_NE12)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_II_NE12(term_condition,command,last_command,...)\
	ZZCPP_WHILE_II13(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_II13(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_II_E,ZZCPP_WHILE_II_NE13)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_II_NE13(term_condition,command,last_command,...)\
	ZZCPP_WHILE_II14(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_II14(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_II_E,ZZCPP_WHILE_II_NE14)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_II_NE14(term_condition,command,last_command,...)\
	ZZCPP_WHILE_II15(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_II15(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_II_E,ZZCPP_WHILE_II_NE15)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_II_NE15(term_condition,command,last_command,...)\
	ZZCPP_WHILE_II16(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_II16(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_II_E,ZZCPP_WHILE_II_NE16)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_II_NE16(term_condition,command,last_command,...)\
	ZZCPP_WHILE_II17(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_II17(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_II_E,ZZCPP_WHILE_II_NE17)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_II_NE17(term_condition,command,last_command,...)\
	ZZCPP_WHILE_II18(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_II18(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_II_E,ZZCPP_WHILE_II_NE18)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_II_NE18(term_condition,command,last_command,...)\
	ZZCPP_WHILE_II19(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_II19(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_II_E,ZZCPP_WHILE_II_NE19)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_II_NE19(term_condition,command,last_command,...)\
	ZZCPP_WHILE_II20(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_II20(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_II_E,ZZCPP_WHILE_II_NE20)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_II_NE20(term_condition,command,last_command,...)\
	ZZCPP_WHILE_II21(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_II21(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_II_E,ZZCPP_WHILE_II_NE21)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_II_NE21(term_condition,command,last_command,...)\
	ZZCPP_WHILE_II22(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_II22(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_II_E,ZZCPP_WHILE_II_NE22)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_II_NE22(term_condition,command,last_command,...)\
	ZZCPP_WHILE_II23(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_II23(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_II_E,ZZCPP_WHILE_II_NE23)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_II_NE23(term_condition,command,last_command,...)\
	ZZCPP_WHILE_II24(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_II24(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_II_E,ZZCPP_WHILE_II_NE24)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_II_NE24(term_condition,command,last_command,...)\
	ZZCPP_WHILE_II25(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_II25(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_II_E,ZZCPP_WHILE_II_NE25)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_II_NE25(term_condition,command,last_command,...)\
	ZZCPP_WHILE_II26(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_II26(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_II_E,ZZCPP_WHILE_II_NE26)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_II_NE26(term_condition,command,last_command,...)\
	ZZCPP_WHILE_II27(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_II27(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_II_E,ZZCPP_WHILE_II_NE27)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_II_NE27(term_condition,command,last_command,...)\
	ZZCPP_WHILE_II28(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_II28(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_II_E,ZZCPP_WHILE_II_NE28)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_II_NE28(term_condition,command,last_command,...)\
	ZZCPP_WHILE_II29(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_II29(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_II_E,ZZCPP_WHILE_II_NE29)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_II_NE29(term_condition,command,last_command,...)\
	ZZCPP_WHILE_II30(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_II30(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_II_E,ZZCPP_WHILE_II_NE30)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_II_NE30(term_condition,command,last_command,...)\
	ZZCPP_WHILE_II31(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_II31(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_II_E,ZZCPP_WHILE_II_NE31)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_II_NE31(term_condition,command,last_command,...)\
	ZZCPP_WHILE_II32(term_condition,command,last_command,command(__VA_ARGS__))

//WHILE_III
#define ZZCPP_WHILE_III_E(term_condition,command,last_command,...)\
	last_command(__VA_ARGS__)

#define ZZCPP_WHILE_III(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_III_E,ZZCPP_WHILE_III_NE)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_III_NE(term_condition,command,last_command,...)\
	ZZCPP_WHILE_III1(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_III1(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_III_E,ZZCPP_WHILE_III_NE1)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_III_NE1(term_condition,command,last_command,...)\
	ZZCPP_WHILE_III2(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_III2(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_III_E,ZZCPP_WHILE_III_NE2)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_III_NE2(term_condition,command,last_command,...)\
	ZZCPP_WHILE_III3(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_III3(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_III_E,ZZCPP_WHILE_III_NE3)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_III_NE3(term_condition,command,last_command,...)\
	ZZCPP_WHILE_III4(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_III4(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_III_E,ZZCPP_WHILE_III_NE4)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_III_NE4(term_condition,command,last_command,...)\
	ZZCPP_WHILE_III5(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_III5(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_III_E,ZZCPP_WHILE_III_NE5)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_III_NE5(term_condition,command,last_command,...)\
	ZZCPP_WHILE_III6(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_III6(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_III_E,ZZCPP_WHILE_III_NE6)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_III_NE6(term_condition,command,last_command,...)\
	ZZCPP_WHILE_III7(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_III7(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_III_E,ZZCPP_WHILE_III_NE7)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_III_NE7(term_condition,command,last_command,...)\
	ZZCPP_WHILE_III8(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_III8(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_III_E,ZZCPP_WHILE_III_NE8)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_III_NE8(term_condition,command,last_command,...)\
	ZZCPP_WHILE_III9(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_III9(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_III_E,ZZCPP_WHILE_III_NE9)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_III_NE9(term_condition,command,last_command,...)\
	ZZCPP_WHILE_III10(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_III10(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_III_E,ZZCPP_WHILE_III_NE10)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_III_NE10(term_condition,command,last_command,...)\
	ZZCPP_WHILE_III11(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_III11(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_III_E,ZZCPP_WHILE_III_NE11)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_III_NE11(term_condition,command,last_command,...)\
	ZZCPP_WHILE_III12(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_III12(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_III_E,ZZCPP_WHILE_III_NE12)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_III_NE12(term_condition,command,last_command,...)\
	ZZCPP_WHILE_III13(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_III13(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_III_E,ZZCPP_WHILE_III_NE13)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_III_NE13(term_condition,command,last_command,...)\
	ZZCPP_WHILE_III14(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_III14(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_III_E,ZZCPP_WHILE_III_NE14)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_III_NE14(term_condition,command,last_command,...)\
	ZZCPP_WHILE_III15(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_III15(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_III_E,ZZCPP_WHILE_III_NE15)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_III_NE15(term_condition,command,last_command,...)\
	ZZCPP_WHILE_III16(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_III16(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_III_E,ZZCPP_WHILE_III_NE16)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_III_NE16(term_condition,command,last_command,...)\
	ZZCPP_WHILE_III17(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_III17(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_III_E,ZZCPP_WHILE_III_NE17)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_III_NE17(term_condition,command,last_command,...)\
	ZZCPP_WHILE_III18(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_III18(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_III_E,ZZCPP_WHILE_III_NE18)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_III_NE18(term_condition,command,last_command,...)\
	ZZCPP_WHILE_III19(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_III19(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_III_E,ZZCPP_WHILE_III_NE19)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_III_NE19(term_condition,command,last_command,...)\
	ZZCPP_WHILE_III20(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_III20(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_III_E,ZZCPP_WHILE_III_NE20)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_III_NE20(term_condition,command,last_command,...)\
	ZZCPP_WHILE_III21(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_III21(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_III_E,ZZCPP_WHILE_III_NE21)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_III_NE21(term_condition,command,last_command,...)\
	ZZCPP_WHILE_III22(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_III22(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_III_E,ZZCPP_WHILE_III_NE22)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_III_NE22(term_condition,command,last_command,...)\
	ZZCPP_WHILE_III23(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_III23(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_III_E,ZZCPP_WHILE_III_NE23)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_III_NE23(term_condition,command,last_command,...)\
	ZZCPP_WHILE_III24(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_III24(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_III_E,ZZCPP_WHILE_III_NE24)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_III_NE24(term_condition,command,last_command,...)\
	ZZCPP_WHILE_III25(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_III25(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_III_E,ZZCPP_WHILE_III_NE25)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_III_NE25(term_condition,command,last_command,...)\
	ZZCPP_WHILE_III26(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_III26(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_III_E,ZZCPP_WHILE_III_NE26)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_III_NE26(term_condition,command,last_command,...)\
	ZZCPP_WHILE_III27(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_III27(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_III_E,ZZCPP_WHILE_III_NE27)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_III_NE27(term_condition,command,last_command,...)\
	ZZCPP_WHILE_III28(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_III28(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_III_E,ZZCPP_WHILE_III_NE28)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_III_NE28(term_condition,command,last_command,...)\
	ZZCPP_WHILE_III29(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_III29(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_III_E,ZZCPP_WHILE_III_NE29)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_III_NE29(term_condition,command,last_command,...)\
	ZZCPP_WHILE_III30(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_III30(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_III_E,ZZCPP_WHILE_III_NE30)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_III_NE30(term_condition,command,last_command,...)\
	ZZCPP_WHILE_III31(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_III31(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_III_E,ZZCPP_WHILE_III_NE31)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_III_NE31(term_condition,command,last_command,...)\
	ZZCPP_WHILE_III32(term_condition,command,last_command,command(__VA_ARGS__))

//WHILE_IV
#define ZZCPP_WHILE_IV_E(term_condition,command,last_command,...)\
	last_command(__VA_ARGS__)

#define ZZCPP_WHILE_IV(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_IV_E,ZZCPP_WHILE_IV_NE)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_IV_NE(term_condition,command,last_command,...)\
	ZZCPP_WHILE_IV1(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_IV1(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_IV_E,ZZCPP_WHILE_IV_NE1)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_IV_NE1(term_condition,command,last_command,...)\
	ZZCPP_WHILE_IV2(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_IV2(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_IV_E,ZZCPP_WHILE_IV_NE2)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_IV_NE2(term_condition,command,last_command,...)\
	ZZCPP_WHILE_IV3(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_IV3(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_IV_E,ZZCPP_WHILE_IV_NE3)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_IV_NE3(term_condition,command,last_command,...)\
	ZZCPP_WHILE_IV4(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_IV4(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_IV_E,ZZCPP_WHILE_IV_NE4)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_IV_NE4(term_condition,command,last_command,...)\
	ZZCPP_WHILE_IV5(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_IV5(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_IV_E,ZZCPP_WHILE_IV_NE5)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_IV_NE5(term_condition,command,last_command,...)\
	ZZCPP_WHILE_IV6(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_IV6(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_IV_E,ZZCPP_WHILE_IV_NE6)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_IV_NE6(term_condition,command,last_command,...)\
	ZZCPP_WHILE_IV7(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_IV7(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_IV_E,ZZCPP_WHILE_IV_NE7)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_IV_NE7(term_condition,command,last_command,...)\
	ZZCPP_WHILE_IV8(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_IV8(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_IV_E,ZZCPP_WHILE_IV_NE8)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_IV_NE8(term_condition,command,last_command,...)\
	ZZCPP_WHILE_IV9(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_IV9(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_IV_E,ZZCPP_WHILE_IV_NE9)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_IV_NE9(term_condition,command,last_command,...)\
	ZZCPP_WHILE_IV10(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_IV10(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_IV_E,ZZCPP_WHILE_IV_NE10)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_IV_NE10(term_condition,command,last_command,...)\
	ZZCPP_WHILE_IV11(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_IV11(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_IV_E,ZZCPP_WHILE_IV_NE11)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_IV_NE11(term_condition,command,last_command,...)\
	ZZCPP_WHILE_IV12(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_IV12(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_IV_E,ZZCPP_WHILE_IV_NE12)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_IV_NE12(term_condition,command,last_command,...)\
	ZZCPP_WHILE_IV13(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_IV13(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_IV_E,ZZCPP_WHILE_IV_NE13)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_IV_NE13(term_condition,command,last_command,...)\
	ZZCPP_WHILE_IV14(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_IV14(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_IV_E,ZZCPP_WHILE_IV_NE14)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_IV_NE14(term_condition,command,last_command,...)\
	ZZCPP_WHILE_IV15(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_IV15(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_IV_E,ZZCPP_WHILE_IV_NE15)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_IV_NE15(term_condition,command,last_command,...)\
	ZZCPP_WHILE_IV16(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_IV16(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_IV_E,ZZCPP_WHILE_IV_NE16)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_IV_NE16(term_condition,command,last_command,...)\
	ZZCPP_WHILE_IV17(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_IV17(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_IV_E,ZZCPP_WHILE_IV_NE17)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_IV_NE17(term_condition,command,last_command,...)\
	ZZCPP_WHILE_IV18(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_IV18(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_IV_E,ZZCPP_WHILE_IV_NE18)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_IV_NE18(term_condition,command,last_command,...)\
	ZZCPP_WHILE_IV19(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_IV19(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_IV_E,ZZCPP_WHILE_IV_NE19)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_IV_NE19(term_condition,command,last_command,...)\
	ZZCPP_WHILE_IV20(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_IV20(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_IV_E,ZZCPP_WHILE_IV_NE20)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_IV_NE20(term_condition,command,last_command,...)\
	ZZCPP_WHILE_IV21(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_IV21(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_IV_E,ZZCPP_WHILE_IV_NE21)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_IV_NE21(term_condition,command,last_command,...)\
	ZZCPP_WHILE_IV22(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_IV22(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_IV_E,ZZCPP_WHILE_IV_NE22)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_IV_NE22(term_condition,command,last_command,...)\
	ZZCPP_WHILE_IV23(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_IV23(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_IV_E,ZZCPP_WHILE_IV_NE23)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_IV_NE23(term_condition,command,last_command,...)\
	ZZCPP_WHILE_IV24(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_IV24(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_IV_E,ZZCPP_WHILE_IV_NE24)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_IV_NE24(term_condition,command,last_command,...)\
	ZZCPP_WHILE_IV25(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_IV25(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_IV_E,ZZCPP_WHILE_IV_NE25)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_IV_NE25(term_condition,command,last_command,...)\
	ZZCPP_WHILE_IV26(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_IV26(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_IV_E,ZZCPP_WHILE_IV_NE26)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_IV_NE26(term_condition,command,last_command,...)\
	ZZCPP_WHILE_IV27(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_IV27(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_IV_E,ZZCPP_WHILE_IV_NE27)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_IV_NE27(term_condition,command,last_command,...)\
	ZZCPP_WHILE_IV28(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_IV28(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_IV_E,ZZCPP_WHILE_IV_NE28)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_IV_NE28(term_condition,command,last_command,...)\
	ZZCPP_WHILE_IV29(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_IV29(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_IV_E,ZZCPP_WHILE_IV_NE29)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_IV_NE29(term_condition,command,last_command,...)\
	ZZCPP_WHILE_IV30(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_IV30(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_IV_E,ZZCPP_WHILE_IV_NE30)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_IV_NE30(term_condition,command,last_command,...)\
	ZZCPP_WHILE_IV31(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_WHILE_IV31(term_condition,command,last_command,...)\
	ZZCPP_IF(term_condition(__VA_ARGS__),\
	ZZCPP_WHILE_IV_E,ZZCPP_WHILE_IV_NE31)\
	(term_condition,command,last_command,__VA_ARGS__)
#define ZZCPP_WHILE_IV_NE31(term_condition,command,last_command,...)\
	ZZCPP_WHILE_IV32(term_condition,command,last_command,command(__VA_ARGS__))

#define ZZCPP_IS_ZERO(x) ZZCPP_NOT(ZZCPP_BOOL(x))
//<=
#define ZZCPP_LEQ(x,y)\
	ZZCPP_WHILE(ZZCPP_LEQ_TERM,ZZCPP_LEQ_COMMAND,ZZCPP_LEQ_LAST,x,y)
#define ZZCPP_LEQ_TERM(x,y) ZZCPP_OR(ZZCPP_IS_ZERO(x),ZZCPP_IS_ZERO(y))
#define ZZCPP_LEQ_COMMAND(x,y) ZZCPP_DEC(x),ZZCPP_DEC(y)
#define ZZCPP_LEQ_LAST(x,y) ZZCPP_IS_ZERO(x)

//>=
#define ZZCPP_GEQ(x,y) ZZCPP_LEQ(y,x)
//<
#define ZZCPP_LES(x,y) ZZCPP_NOT(ZZCPP_GEQ(x,y))
//>
#define ZZCPP_GRT(x,y) ZZCPP_NOT(ZZCPP_LEQ(x,y))
//==
#define ZZCPP_EQL(x,y) ZZCPP_AND(ZZCPP_LEQ(x,y),ZZCPP_GEQ(x,y))
//!=
#define ZZCPP_NEQ(x,y) ZZCPP_OR(ZZCPP_LES(x,y),ZZCPP_GRT(x,y))

//+
#define ZZCPP_ADD(x,y)\
	ZZCPP_WHILE(ZZCPP_ADD_TERM,ZZCPP_ADD_COMMAND,ZZCPP_ADD_LAST,x,y)
#define ZZCPP_ADD_TERM(x,y) ZZCPP_IS_ZERO(x)
#define ZZCPP_ADD_COMMAND(x,y) ZZCPP_DEC(x),ZZCPP_INC(y)
#define ZZCPP_ADD_LAST(x,y) y

//-
#define ZZCPP_SUB(x,y)\
	ZZCPP_WHILE(ZZCPP_SUB_TERM,ZZCPP_SUB_COMMAND,ZZCPP_SUB_LAST,x,y)
#define ZZCPP_SUB_TERM(x,y) ZZCPP_IS_ZERO(y)
#define ZZCPP_SUB_COMMAND(x,y) ZZCPP_DEC(x),ZZCPP_DEC(y)
#define ZZCPP_SUB_LAST(x,y) x

//*
#define ZZCPP_MUL(x,y)\
	ZZCPP_IF(ZZCPP_OR(ZZCPP_IS_ZERO(x),ZZCPP_IS_ZERO(y)),\
		ZZCPP_MUL_ZERO,ZZCPP_MUL_NZERO)(x,y)
#define ZZCPP_MUL_ZERO(x,y) 0
#define ZZCPP_MUL_NZERO(x,y)\
	ZZCPP_WHILE_II(ZZCPP_MUL_TERM,ZZCPP_MUL_COMMAND,ZZCPP_MUL_LAST,ZZCPP_DEC(x),y,y)
#define ZZCPP_MUL_TERM(x,y,ans) ZZCPP_IS_ZERO(x)
#define ZZCPP_MUL_COMMAND(x,y,ans) ZZCPP_DEC(x),y,ZZCPP_ADD(y,ans)
#define ZZCPP_MUL_LAST(x,y,ans) ans

// /
#define ZZCPP_DIV(x,y)\
	ZZCPP_IF(ZZCPP_IS_ZERO(y),ZZCPP_DIV_ZERO,ZZCPP_DIV_NZERO)(x,y)
#define ZZCPP_DIV_ZERO(x,y) y##-must not be 0
#define ZZCPP_DIV_NZERO(x,y)\
	ZZCPP_WHILE_II(ZZCPP_DIV_TERM,ZZCPP_DIV_COMMAND,ZZCPP_DIV_LAST,x,y,0)
#define ZZCPP_DIV_TERM(x,y,ans) ZZCPP_LES(x,y)
#define ZZCPP_DIV_COMMAND(x,y,ans) ZZCPP_SUB(x,y),y,ZZCPP_INC(ans)
#define ZZCPP_DIV_LAST(x,y,ans) ans

// %
#define ZZCPP_MOD(x,y) ZZCPP_SUB(x,ZZCPP_MUL(ZZCPP_DIV(x,y),y))

#endif//!defined(ZZCPP_ECHO)
