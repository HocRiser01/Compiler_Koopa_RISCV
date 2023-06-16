%code requires {
    #include <string>
    #include "../../../ObjTree/ObjManager.h"
}

%{

// 声明 lexer 函数和错误处理函数
int yylex();
extern int line_number;

#include "../../../ObjTree/ObjManager.h"
void yyerror(ObjTree::ObjManager* obj_manager, const char *s);

using namespace std;

%}

%parse-param { ObjTree::ObjManager* obj_manager  }

// available retrun value type for `yylval`
%union {
    ObjTree::ObjUuid node_uuid;
    const char* raw_string;
}

// lexer 返回的所有 token 种类的声明
%token <raw_string> KEYWORD_INT_FUNC KEYWORD_FLOAT_FUNC SEMICOLON COMMA EQUAL
%token <raw_string> LBRACKET RBRACKET LBRACE RBRACE LPARE RPARE OPE_NOT OPE_ADD OPE_SUB OPE_MUL
%token <raw_string> OPE_DIV OPE_MOD OPE_AND OPE_OR OPE_EQU OPE_NEQ OPE_LEQ OPE_GEQ OPE_LSS OPE_GTR
%token <raw_string> DECIMAL_CONST OCTAL_CONST HEXADECIMAL_CONST FLOAT_CONST IDENTIFIER KEYWORD_CONST
%token <raw_string> KEYWORD_INT KEYWORD_FLOAT KEYWORD_VOID KEYWORD_IF KEYWORD_ELSE KEYWORD_WHILE
%token <raw_string> KEYWORD_CONTINUE KEYWORD_BREAK KEYWORD_RETURN

// 非终结符的类型定义
%type <node_uuid> CompUnit CompUnitDef Decl ConstDecl BType ConstDefList ConstDef
%type <node_uuid> ArrayIndexList InitVal InitValList VarDecl VarDefList VarDef FuncDef FuncType
%type <node_uuid> FuncFParams FuncFParam FuncFParamArrayIndexList Block BlockItemList BlockItem
%type <node_uuid> Stmt IntConst FloatConst Exp Cond LVal PrimaryExp Number UnaryExp UnaryOp
%type <node_uuid> FuncRPAREms MulExp MulOp AddExp AddOp RelExp RelOp EqExp EqOp LAndExp LOrExp

%%

CompUnit
    : CompUnitDef 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "CompUnitAst");
            obj_manager->add_son(uuid, {$1});
            $$ = uuid;
        }
    | CompUnit CompUnitDef 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "CompUnitAst");
            obj_manager->add_son(uuid, {$1, $2});
            $$ = uuid;
        }
;

CompUnitDef
    : Decl 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "CompUnitDefAst");
            obj_manager->add_son(uuid, {$1});
            $$ = uuid;
        }
    | FuncDef 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "CompUnitDefAst");
            obj_manager->add_son(uuid, {$1});
            $$ = uuid;
        }
;

Decl
    : ConstDecl 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "DeclAst");
            obj_manager->add_son(uuid, {$1});
            $$ = uuid;
        }
    | VarDecl 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "DeclAst");
            obj_manager->add_son(uuid, {$1});
            $$ = uuid;
        }
;

ConstDecl
    : KEYWORD_CONST BType ConstDefList SEMICOLON 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "ConstDeclAst");
            obj_manager->add_son(uuid, {$2, $3});
            $$ = uuid;
        }
;

BType
    : KEYWORD_INT 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "BTypeAst");
            obj_manager->set_info(uuid, "KEYWORD_INT");
            $$ = uuid;
        }
    | KEYWORD_FLOAT 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "BTypeAst");
            obj_manager->set_info(uuid, "KEYWORD_FLOAT");
            $$ = uuid;
        }
;

ConstDefList
    : ConstDef 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "ConstDefListAst");
            obj_manager->add_son(uuid, {$1});
            $$ = uuid;
        }
    | ConstDefList COMMA ConstDef 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "ConstDefListAst");
            obj_manager->add_son(uuid, {$1, $3});
            $$ = uuid;
        }
;

ConstDef
    : IDENTIFIER ArrayIndexList EQUAL InitVal 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "ConstDefAst");
            obj_manager->set_info(uuid, $1);
            obj_manager->add_son(uuid, {$2, $4});
            $$ = uuid;
        }
;

ArrayIndexList
    : 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "ArrayIndexListAst"); // no sons
            $$ = uuid;
        }
    | ArrayIndexList LBRACKET Exp RBRACKET 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "ArrayIndexListAst");
            obj_manager->add_son(uuid, {$1, $3});
            $$ = uuid;
        }
;

InitVal
    : Exp 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "InitValAst");
            obj_manager->set_info(uuid, "Exp"); // single exp
            obj_manager->add_son(uuid, {$1});
            $$ = uuid;
        }
    | LBRACE InitValList RBRACE 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "InitValAst");
            obj_manager->set_info(uuid, "InitValList"); // initialization list
            obj_manager->add_son(uuid, {$2});
            $$ = uuid;
        }
;

InitValList
    : InitVal 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "InitValListAst");
            obj_manager->add_son(uuid, {$1});
            $$ = uuid;
        }
    | InitValList COMMA InitVal 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "InitValListAst");
            obj_manager->add_son(uuid, {$1, $3});
            $$ = uuid;
        }
;

VarDecl
    : BType VarDefList SEMICOLON 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "VarDeclAst");
            obj_manager->add_son(uuid, {$1, $2});
            $$ = uuid;
        }
;

VarDefList
    : VarDef 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "VarDefListAst");
            obj_manager->add_son(uuid, {$1});
            $$ = uuid;
        }
    | VarDefList COMMA VarDef 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "VarDefListAst");
            obj_manager->add_son(uuid, {$1, $3});
            $$ = uuid;
        }
;

VarDef
    : IDENTIFIER ArrayIndexList 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "VarDefAst");
            obj_manager->set_info(uuid, $1);
            obj_manager->add_son(uuid, {$2});
            $$ = uuid;
        }
    | IDENTIFIER ArrayIndexList EQUAL InitVal 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "VarDefAst");
            obj_manager->set_info(uuid, $1);
            obj_manager->add_son(uuid, {$2, $4});
            $$ = uuid;
        }
;

FuncDef
    : FuncType IDENTIFIER LPARE RPARE Block 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "FuncDefAst");
            obj_manager->set_info(uuid, $2);
            obj_manager->add_son(uuid, {$1, $5});
            $$ = uuid;
        }
    | FuncType IDENTIFIER LPARE FuncFParams RPARE Block 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "FuncDefAst");
            obj_manager->set_info(uuid, $2);
            obj_manager->add_son(uuid, {$1, $4, $6});
            $$ = uuid;
        }
;

FuncType
    : KEYWORD_VOID 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "FuncTypeAst");
            obj_manager->set_info(uuid, $1);
            $$ = uuid;
        }
    | KEYWORD_INT_FUNC 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "FuncTypeAst");
            obj_manager->set_info(uuid, $1);
            $$ = uuid;
        }
    | KEYWORD_FLOAT_FUNC 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "FuncTypeAst");
            obj_manager->set_info(uuid, $1);
            $$ = uuid;
        }
;

FuncFParams
    : FuncFParam 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "FuncFParamsAst");
            obj_manager->add_son(uuid, {$1});
            $$ = uuid;
        }
    | FuncFParams COMMA FuncFParam 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "FuncFParamsAst");
            obj_manager->add_son(uuid, {$1, $3});
            $$ = uuid;
        }
;

FuncFParam
    : BType IDENTIFIER FuncFParamArrayIndexList 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "FuncFParamAst");
            obj_manager->set_info(uuid, $2);
            obj_manager->add_son(uuid, {$1, $3});
            $$ = uuid;
        }
;

FuncFParamArrayIndexList
    :   {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "FuncFParamArrayIndexListAst");
            obj_manager->set_info(uuid, "Empty");
            $$ = uuid;
        }
    | LBRACKET RBRACKET
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "FuncFParamArrayIndexListAst");
            $$ = uuid;
        }
    | FuncFParamArrayIndexList LBRACKET Exp RBRACKET 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "FuncFParamArrayIndexListAst");
            obj_manager->add_son(uuid, {$1, $3});
            $$ = uuid;
        }
;

Block
    : LBRACE BlockItemList RBRACE 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "BlockAst");
            obj_manager->add_son(uuid, {$2});
            $$ = uuid;
        }
;

BlockItemList
    : 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "BlockItemListAst");
            $$ = uuid;
        }
    | BlockItemList BlockItem 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "BlockItemListAst");
            obj_manager->add_son(uuid, {$1, $2});
            $$ = uuid;
        }
;

BlockItem
    : Decl 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "BlockItemAst");
            obj_manager->add_son(uuid, {$1}); // 通过子节点类型区分
            $$ = uuid;
        }
    | Stmt 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "BlockItemAst");
            obj_manager->add_son(uuid, {$1}); // 通过子节点类型区分
            $$ = uuid;
        }
;

Stmt
    : LVal EQUAL Exp SEMICOLON 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "StmtAst");
            obj_manager->add_son(uuid, {$1, $3}); // 区分不同产生式的方法：根据子节点的个数和类型
            $$ = uuid;
        }
    | SEMICOLON 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "StmtAst");
            $$ = uuid;
        }
    | Exp SEMICOLON 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "StmtAst");
            obj_manager->add_son(uuid, {$1});
            $$ = uuid;
        }
    | Block 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "StmtAst");
            obj_manager->add_son(uuid, {$1});
            $$ = uuid;
        }
    | KEYWORD_IF LPARE Cond RPARE Stmt 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "StmtAst");
            obj_manager->set_info(uuid, "If"); // 区分 If, IfElse, While 不得不使用 info
            obj_manager->add_son(uuid, {$3, $5});
            $$ = uuid;
        }
    | KEYWORD_IF LPARE Cond RPARE Stmt KEYWORD_ELSE Stmt 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "StmtAst");
            obj_manager->set_info(uuid, "IfElse");
            obj_manager->add_son(uuid, {$3, $5, $7});
            $$ = uuid;
        }
    | KEYWORD_WHILE LPARE Cond RPARE Stmt 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "StmtAst");
            obj_manager->set_info(uuid, "While");
            obj_manager->add_son(uuid, {$3, $5});
            $$ = uuid;
        }
    | KEYWORD_BREAK SEMICOLON 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "StmtAst");
            obj_manager->set_info(uuid, "Break"); // 区分空语句，Break, Continue, Return 也需要使用 info
            $$ = uuid;
        }
    | KEYWORD_CONTINUE SEMICOLON 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "StmtAst");
            obj_manager->set_info(uuid, "Continue");
            $$ = uuid;
        }
    | KEYWORD_RETURN SEMICOLON 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "StmtAst");
            obj_manager->set_info(uuid, "Return");
            $$ = uuid;
        }
    | KEYWORD_RETURN Exp SEMICOLON 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "StmtAst");
            obj_manager->set_info(uuid, "ReturnExp");
            obj_manager->add_son(uuid, {$2});
            $$ = uuid;
        }
;

IntConst
    : DECIMAL_CONST 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "IntConstAst");
            obj_manager->set_info(uuid, $1);
            $$ = uuid;
        }
    | OCTAL_CONST 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "IntConstAst");
            obj_manager->set_info(uuid, $1);
            $$ = uuid;
        }
    | HEXADECIMAL_CONST 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "IntConstAst");
            obj_manager->set_info(uuid, $1);
            $$ = uuid;
        }
;

FloatConst
    : FLOAT_CONST 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "FloatConstAst");
            obj_manager->set_info(uuid, $1);
            $$ = uuid;
        }
;

Exp
    : AddExp 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "ExpAst");
            obj_manager->add_son(uuid, {$1});
            $$ = uuid;
        }
;

Cond
    : LOrExp 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "CondAst");
            obj_manager->add_son(uuid, {$1});
            $$ = uuid;
        }
;

LVal
    : IDENTIFIER ArrayIndexList 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "LValAst");
            obj_manager->set_info(uuid, $1);
            obj_manager->add_son(uuid, {$2});
            $$ = uuid;
        }
;

PrimaryExp
    : LPARE Exp RPARE 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "PrimaryExpAst");
            obj_manager->add_son(uuid, {$2});
            $$ = uuid;
        }
    | LVal 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "PrimaryExpAst");
            obj_manager->add_son(uuid, {$1});
            $$ = uuid;
        }
    | Number 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "PrimaryExpAst");
            obj_manager->add_son(uuid, {$1});
            $$ = uuid;
        }
;

Number
    : IntConst 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "NumberAst");
            obj_manager->add_son(uuid, {$1});
            $$ = uuid;
        }
    | FloatConst 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "NumberAst");
            obj_manager->add_son(uuid, {$1});
            $$ = uuid;
        }
;

UnaryExp
    : PrimaryExp 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "UnaryExpAst");
            obj_manager->add_son(uuid, {$1});
            $$ = uuid;
        }
    | IDENTIFIER LPARE RPARE 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "UnaryExpAst");
            obj_manager->set_info(uuid, $1);
            $$ = uuid;
        }
    | IDENTIFIER LPARE FuncRPAREms RPARE 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "UnaryExpAst");
            obj_manager->set_info(uuid, $1);
            obj_manager->add_son(uuid, {$3}); // 通过 info 和参数个数区分产生式
            $$ = uuid;
        }
    | UnaryOp UnaryExp 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "UnaryExpAst");
            obj_manager->add_son(uuid, {$1, $2});
            $$ = uuid;
        }
;

UnaryOp
    : OPE_ADD 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "UnaryOpAst");
            obj_manager->set_info(uuid, $1);
            $$ = uuid;
        }
    | OPE_SUB 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "UnaryOpAst");
            obj_manager->set_info(uuid, $1);
            $$ = uuid;
        }
    | OPE_NOT 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "UnaryOpAst");
            obj_manager->set_info(uuid, $1);
            $$ = uuid;
        }
;

FuncRPAREms
    : Exp 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "FuncRPAREmsAst");
            obj_manager->add_son(uuid, {$1});
            $$ = uuid;
        }
    | FuncRPAREms COMMA Exp 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "FuncRPAREmsAst");
            obj_manager->add_son(uuid, {$1, $3});
            $$ = uuid;
        }
;

MulExp
    : UnaryExp 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "MulExpAst");
            obj_manager->add_son(uuid, {$1});
            $$ = uuid;
        }
    | MulExp MulOp UnaryExp 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "MulExpAst");
            obj_manager->add_son(uuid, {$1, $2, $3});
            $$ = uuid;
        }
;

MulOp
    : OPE_MUL 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "MulOpAst");
            obj_manager->set_info(uuid, "*");
            $$ = uuid;
        }
    | OPE_DIV 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "MulOpAst");
            obj_manager->set_info(uuid, "/");
            $$ = uuid;
        }
    | OPE_MOD 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "MulOpAst");
            obj_manager->set_info(uuid, "%");
            $$ = uuid;
        }
;

AddExp
    : MulExp 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "AddExpAst");
            obj_manager->add_son(uuid, {$1});
            $$ = uuid;
        }
    | AddExp AddOp MulExp 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "AddExpAst");
            obj_manager->add_son(uuid, {$1, $2, $3});
            $$ = uuid;
        }
;

AddOp
    : OPE_ADD 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "AddOpAst");
            obj_manager->set_info(uuid, "+");
            $$ = uuid;
        }
    | OPE_SUB 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "AddOpAst");
            obj_manager->set_info(uuid, "-");
            $$ = uuid;
        }
;

RelExp
    : AddExp 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "RelExpAst");
            obj_manager->add_son(uuid, {$1});
            $$ = uuid;
        }
    | RelExp RelOp AddExp 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "RelExpAst");
            obj_manager->add_son(uuid, {$1, $2, $3});
            $$ = uuid;
        }
;

RelOp
    : OPE_LSS 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "RelOpAst");
            obj_manager->set_info(uuid, "<");
            $$ = uuid;
        }
    | OPE_LEQ 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "RelOpAst");
            obj_manager->set_info(uuid, "<=");
            $$ = uuid;
        }
    | OPE_GTR 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "RelOpAst");
            obj_manager->set_info(uuid, ">");
            $$ = uuid;
        }
    | OPE_GEQ 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "RelOpAst");
            obj_manager->set_info(uuid, ">=");
            $$ = uuid;
        }
;

EqExp
    : RelExp 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "EqExpAst");
            obj_manager->add_son(uuid, {$1});
            $$ = uuid;
        }
    | EqExp EqOp RelExp 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "EqExpAst");
            obj_manager->add_son(uuid, {$1, $2, $3});
            $$ = uuid;
        }
;

EqOp
    : OPE_EQU 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "EqOpAst");
            obj_manager->set_info(uuid, "==");
            $$ = uuid;
        }
    | OPE_NEQ 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "EqOpAst");
            obj_manager->set_info(uuid, "!=");
            $$ = uuid;
        }
;

LAndExp
    : EqExp 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "LAndExpAst");
            obj_manager->add_son(uuid, {$1});
            $$ = uuid;
        }
    | LAndExp OPE_AND EqExp 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "LAndExpAst");
            obj_manager->add_son(uuid, {$1, $3});
            $$ = uuid;
        }
;

LOrExp
    : LAndExp 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "LOrExpAst");
            obj_manager->add_son(uuid, {$1});
            $$ = uuid;
        }
    | LOrExp OPE_OR LAndExp 
        {
            ObjTree::ObjUuid uuid = obj_manager->get_uuid();
            obj_manager->set_type(uuid, "LOrExpAst");
            obj_manager->add_son(uuid, {$1, $3});
            $$ = uuid;
        }
;

%%

int line_number = 1;

// output error message
void yyerror(ObjTree::ObjManager* obj_manager, const char *s) {
  cerr << make_error_message((std::string(s) + " line in sy code: " + std::to_string(line_number)).c_str()) << endl;
}
