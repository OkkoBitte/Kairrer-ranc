#include "bed.hpp"
vars kairrer(std::string code,std::vector<std::string> argm){
    std::vector<TOKENS> tokens = tokenizer(code);
    urwerer state;
    kairrer_tpr ktpr(tokens, state);
    std::vector<vars> varsarg;
    std::string args;
    int argi=1;
    for(auto arg:argm){
        vars nwar;
        nwar.name="arg"+std::to_string(argi);
        nwar.valib.type=VSID::stringV;
        nwar.valib.value=arg;
        args+=' '+arg;
        varsarg.push_back(nwar);
        argi++;
    } 
    vars nware;
    nware.name="args";
    nware.valib.type=VSID::stringV;
    nware.valib.value=args;
    varsarg.push_back(nware);
    

    vars AP;
    AP.name = "AP";
    AP.valib.type = VSID::intV;
    AP.valib.value = AP__KRR;
    varsarg.push_back(AP);

    vars BIN;
    BIN.name = "BIN";
    BIN.valib.type = VSID::intV;
    BIN.valib.value = BIN__KRR;
    varsarg.push_back(BIN);

    vars FO;
    FO.name = "FO";
    FO.valib.type = VSID::intV;
    FO.valib.value = FO__KRR;
    varsarg.push_back(FO);

    vars return_var;
    std::vector<vars> retvars = ktpr.prun(varsarg);
    for(auto retvar : retvars){ if (retvar.name == defretvarname) return_var = retvar; }
    return return_var;
}