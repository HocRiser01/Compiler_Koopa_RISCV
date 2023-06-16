
# 每级缩进四个空格
LINE_PREFIX = "    "

# 解析序列化后的抽象语法树
# 这部分内容与编译无关，仅用来方便测试
def make_seq_into_list(seq_ast: str):
    indent = 0
    lis = [""]
    for c in seq_ast:
        if c == "{" or c == "}" or c == ",":
            lis.append(c)
            lis.append("")
        else:
            lis[-1] += c
    lis = [x for x in lis if x != ""]
    return lis

def get_prefix_by_indent(indent):
    return ".   " * indent

# 美化输出抽象语法树的调试信息
def pretty(seq_ast: str):
    lis = make_seq_into_list(seq_ast)
    indent = 0
    ans = ""
    for component in lis:
        if component == "{":
            ans += get_prefix_by_indent(indent) + "{\n"
            indent += 1
        elif component == "}":
            indent -= 1
            ans += get_prefix_by_indent(indent) + "}\n"
        else:
            ans += get_prefix_by_indent(indent) + component + "\n"
    return ans

TEST_SEQ_STR = """
138(CompUnitAst)[]{137(CompUnitDefAst)[]{136(FuncDefAst)[main]{1(FuncTypeAst)[int]{},135(BlockAst)[]{134(BlockItemListAst)[]{124(BlockItemListAst)[]{53(BlockItemListAst)[]{37(BlockItemListAst)[]{2(BlockItemListAst)[]{},36(BlockItemAst)[]{35(DeclAst)[]{34(VarDeclAst)[]{3(BTypeAst)[KEYWORD_INT]{},33(VarDefListAst)[]{32(VarDefAst)[x]{12(ArrayIndexListAst)[]{4(ArrayIndexListAst)[]{},11(ExpAst)[]{10(AddExpAst)[]{9(MulExpAst)[]{8(UnaryExpAst)[]{7(PrimaryExpAst)[]{6(NumberAst)[]{5(IntConstAst)[2]{}}}}}}}},31(InitValAst)[InitValList]{30(InitValListAst)[]{21(InitValListAst)[]{20(InitValAst)[Exp]{19(ExpAst)[]{18(AddExpAst)[]{17(MulExpAst)[]{16(UnaryExpAst)[]{15(PrimaryExpAst)[]{14(NumberAst)[]{13(IntConstAst)[0]{}}}}}}}}},29(InitValAst)[Exp]{28(ExpAst)[]{27(AddExpAst)[]{26(MulExpAst)[]{25(UnaryExpAst)[]{24(PrimaryExpAst)[]{23(NumberAst)[]{22(IntConstAst)[1]{}}}}}}}}}}}}}}}},52(BlockItemAst)[]{51(DeclAst)[]{50(VarDeclAst)[]{38(BTypeAst)[KEYWORD_INT]{},49(VarDefListAst)[]{48(VarDefAst)[i]{39(ArrayIndexListAst)[]{},47(InitValAst)[Exp]{46(ExpAst)[]{45(AddExpAst)[]{44(MulExpAst)[]{43(UnaryExpAst)[]{42(PrimaryExpAst)[]{41(NumberAst)[]{40(IntConstAst)[0]{}}}}}}}}}}}}}},123(BlockItemAst)[]{122(StmtAst)[While]{72(CondAst)[]{71(LOrExpAst)[]{70(LAndExpAst)[]{69(EqExpAst)[]{68(RelExpAst)[]{60(RelExpAst)[]{59(AddExpAst)[]{58(MulExpAst)[]{57(UnaryExpAst)[]{56(PrimaryExpAst)[]{55(LValAst)[i]{54(ArrayIndexListAst)[]{}}}}}}},61(RelOpAst)[<=]{},67(AddExpAst)[]{66(MulExpAst)[]{65(UnaryExpAst)[]{64(PrimaryExpAst)[]{63(NumberAst)[]{62(IntConstAst)[1]{}}}}}}}}}}},121(StmtAst)[]{120(BlockAst)[]{119(BlockItemListAst)[]{100(BlockItemListAst)[]{73(BlockItemListAst)[]{},99(BlockItemAst)[]{98(StmtAst)[]{83(LValAst)[x]{82(ArrayIndexListAst)[]{74(ArrayIndexListAst)[]{},81(ExpAst)[]{80(AddExpAst)[]{79(MulExpAst)[]{78(UnaryExpAst)[]{77(PrimaryExpAst)[]{76(LValAst)[i]{75(ArrayIndexListAst)[]{}}}}}}}}},97(ExpAst)[]{96(AddExpAst)[]{89(AddExpAst)[]{88(MulExpAst)[]{87(UnaryExpAst)[]{86(PrimaryExpAst)[]{85(LValAst)[i]{84(ArrayIndexListAst)[]{}}}}}},90(AddOpAst)[+]{},95(MulExpAst)[]{94(UnaryExpAst)[]{93(PrimaryExpAst)[]{92(NumberAst)[]{91(IntConstAst)[1]{}}}}}}}}}},118(BlockItemAst)[]{117(StmtAst)[]{102(LValAst)[i]{101(ArrayIndexListAst)[]{}},116(ExpAst)[]{115(AddExpAst)[]{108(AddExpAst)[]{107(MulExpAst)[]{106(UnaryExpAst)[]{105(PrimaryExpAst)[]{104(LValAst)[i]{103(ArrayIndexListAst)[]{}}}}}},109(AddOpAst)[+]{},114(MulExpAst)[]{113(UnaryExpAst)[]{112(PrimaryExpAst)[]{111(NumberAst)[]{110(IntConstAst)[1]{}}}}}}}}}}}}}}},133(BlockItemAst)[]{132(StmtAst)[ReturnExp]{131(ExpAst)[]{130(AddExpAst)[]{129(MulExpAst)[]{128(UnaryExpAst)[]{127(PrimaryExpAst)[]{126(NumberAst)[]{125(IntConstAst)[0]{}}}}}}}}}}}}}}""".replace("\n", "")

print(pretty(TEST_SEQ_STR))
