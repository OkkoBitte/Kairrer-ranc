#include <vector>
#include <cstdlib> // system()

#include <iostream>
#include <vector>
#include <sstream>
#include <list>
#include <set>
#include <string>
#include <memory>
#include <optional>
#include <array>
#include <stdexcept>
#include <cstdio>
#include <unordered_map>
#include <cstdint>
#include <cstring> 
#include <stdexcept>
#include <algorithm> 
#include <fcntl.h>
#include <unistd.h>
#include <any>
#include <sys/mman.h>

#include "tk.hpp"
#include "lib/tcc.hpp" // x
#include "lib/nwf.hpp"
#include "lib/rmc.hpp"

#define NULL_STR ""
#define VERSION_CODE__KRR 10
#define VERSION_NAME__KRR "0.1.0"
#define defretvarname "return"
#define defargvarname "argument"
enum __vawer { CU_SPI , CU_SI, /* === */   CE_SPI , CE_SI};
enum VSID{ stringV, runV, intV, hexV, nullV };
std::string get_sname_from_vname(VSID VNAME){
    std::string return_vname="<fater>";
    
    if      (VNAME == stringV) return_vname = "<stringV>";
    else if(VNAME == intV)     return_vname = "<intV>";
    else if(VNAME == nullV)    return_vname = "<hexV>";
    else if(VNAME == runV)     return_vname = "<runV>";
    else if(VNAME == nullV)    return_vname = "<nullV>";

    return return_vname;
}

struct vars;
struct value {
    VSID type;
    std::string value;

    bool va_ap; // ?(var)
    std::vector<vars> rargs; 
};

struct vars {
    std::string name;
    value valib;
};





bool is_valid_descriptor(int fd) { return fcntl(fd, F_GETFD) != -1 || errno != EBADF; }

class LOG{
    public:
    static void krr(std::string v){
        std::cerr<<red<<"|[KAIR]"<<v<<reset<<std::endl;
    }
    static void cev(std::string v){
        std::cerr<<yellow<<"|[CELEM] "<<v<<reset<<std::endl;
    }
    static void fkr(std::string ut,std::string v){
        krr("|["+ut+"] "+v);
        exit(1);
    }
};

class urwerer {
    std::unordered_map<std::string, vars> variables;
    
public:
    void addVariable(const vars& var) {
        //removeVariable(var.name);
        variables[var.name] = var;
    }
    std::optional<vars> getVariable(const std::string& name) const {
        auto it = variables.find(name);
        return it != variables.end() ? std::optional(it->second) : std::nullopt;
    }
    std::vector<vars> getVariables(){
        std::vector<vars> variablis;
        for(auto var : variables){
            std::pair<std::string,vars> vare=var;
            variablis.push_back(vare.second);
        }
        return variablis;
    }
    bool removeVariable(const std::string& name) {
        auto  dwar= getVariable(name);
        
        if (dwar->valib.type==intV){
            int descis;
            try{ 
                descis = atoi(dwar->valib.value.c_str());
                if (is_valid_descriptor(descis))  close(descis);
                
            }catch(...){}
            
        };

        return variables.erase(name) > 0;
    }
    std::string executeCommand(const std::string& command) const {
        std::array<char, 128> buffer;
        std::string result;
        std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(command.c_str(), "r"), pclose);
        if (!pipe) throw std::runtime_error("Command execution failed: " + command);
        while (fgets(buffer.data(), buffer.size(), pipe.get())) result += buffer.data();
        return result;
    }
    std::vector<TOKENS> lixtLiber(const std::string&path){
        std::vector<TOKENS> tokens;
        std::string code;
        LOG log;
        if(!file::is_file(path))log.fkr("LIXTLIB","vah per Et -> "+path + "\n");        
        code = file::read_file<std::string>(path);
        
        tokens = tokenizer(code);
        return tokens;
        
    }
    class ASM{
        struct x86comas{
            uint64_t rax = 0; 
            uint64_t rdi = 0; 
            uint64_t rsi = 0; 
            uint64_t rdx = 0; 
            uint64_t r10 = 0;
            uint64_t r8 = 0; 
            uint64_t r9 = 0; 
            std::vector<std::vector<char>> string_storage;
        };
        struct exasm{
            enum whoa{
                intR,stringR
            };
            whoa varet;
            std::string value;
        
        };
        uint64_t getstrreg(x86comas &regists,const std::string& str) {
            std::vector<char> stored_str(str.begin(), str.end());
            stored_str.push_back('\0');
            regists.string_storage.push_back(std::move(stored_str));
            return reinterpret_cast<uint64_t>(regists.string_storage.back().data());
        }
        uint64_t ASM_Exec(x86comas &regists) {
            
            long long syscall_result;
            // std::cout<<"DEBUG: Calling syscall with: rax=0x"<<std::hex<<regists.rax
            // <<"; rdi=0x"<<regists.rdi
            // <<"; rsi=0x"<<regists.rsi
            // <<"; rdx=0x"<<regists.rdx<<std::dec<<std::endl;

            asm volatile (
                "syscall\n" 
                : "=a" (syscall_result) 
                : "a" (regists.rax),   
                  "D" (regists.rdi),   
                  "S" (regists.rsi),   
                  "d" (regists.rdx)     
                : "rcx", "r11"         
            );
    
           
            return static_cast<uint64_t>(syscall_result);
        }
        public:
        uint64_t executeASM(std::string raw_asm) {
            std::vector<TOKENS> tokens= tokenizer(raw_asm);
            x86comas intoLib; 
            int wholisten=0;
            int enpin=0;
         
            LOG log;

            while (enpin<tokens.size()){
                
                if (tokens[enpin].type==STRING){
                   
                    int newpin = enpin;
                    std::string resultstring;
                    while (newpin<tokens.size()&&tokens[newpin].type==STRING){
                        resultstring+=tokens[newpin].value;
                        newpin++;
                    }
                    if     (resultstring=="rax") wholisten=1;
                    else if(resultstring=="rdi") wholisten=2;
                    else if(resultstring=="rsi") wholisten=3;
                    else if(resultstring=="rdx") wholisten=4;
                    else if(resultstring=="r10") wholisten=5;
                    else if(resultstring=="r8")  wholisten=6;
                    else if(resultstring=="r9")  wholisten=7;
                    else log.fkr("ASMRUN","vah comand et -> "+resultstring+" ?");
                    enpin=newpin;
                    
                
                }
                else if(tokens[enpin].type==INT||tokens[enpin].type==S||tokens[enpin].type==SS||tokens[enpin].type==SI) {
                    if(tokens[enpin].type==INT || tokens[enpin].type==SI ){
                        
                        std::string resultint;

                        int newpin   = enpin;
                        bool reverse = false;

                        bool ishex   = false;
                        bool isottom = false;
                        bool isbin   = false;

                        if(tokens[newpin].type==SI){reverse=true;newpin++;if(tokens[newpin].type!=INT) log.fkr("ANSRUN"," -int <- vapin?");}
      
                        while (newpin<tokens.size()&&(tokens[newpin].type==INT || tokens[newpin].type==STRING)){
                            if(tokens[newpin].type==STRING){
                                     if(tokens[newpin].value=="x" && resultint=="0") ishex =true;
                                else if(tokens[newpin].value=="b" && resultint=="0") isbin=true;
                                else if(tokens[newpin].value=="o" && resultint=="0") isottom=true;
                                else log.fkr ("ASMRUN","gat lib -> "+tokens[newpin].value);
                            }
                            resultint+=tokens[newpin].value;
                            newpin++;
                        }
                        //std::cout<<ishex<<":"<<isottom<<std::endl;
                        try {
                                 if(ishex  && !isottom && !isbin) resultint = std::to_string(std::stoi(resultint.substr(2), nullptr, 16));
                            else if(!ishex && isottom && !isbin) resultint = std::to_string(std::stoi(resultint.substr(2), nullptr, 8));
                            else if(!ishex && !isottom && isbin) resultint = std::to_string(std::stoi(resultint.substr(2), nullptr, 2));
                            else if(!ishex && !isottom && !isbin) resultint = resultint;
                            else log.fkr("ASMRUN","gat lib et ret");
                        }
                        catch (const std::exception& e) {
                            log.fkr("ASMRUN", "gat lib: " + resultint);
                        }
                        int resultvalue = atoi(resultint.c_str());

                        if(reverse)resultvalue= resultvalue - (resultvalue*2);
                        
                        
                        switch(wholisten){
                            case 1 : intoLib.rax= resultvalue;break;
                            case 2 : intoLib.rdi= resultvalue;break;
                            case 3 : intoLib.rsi= resultvalue;break;
                            case 4 : intoLib.rdx= resultvalue;break;
                            case 5 : intoLib.r10= resultvalue;break;
                            case 6 : intoLib.r8= resultvalue;break;
                            case 7 : intoLib.r9= resultvalue;break;
                            
                        }
                        enpin=newpin;
                
                        
                    }
                    else if(tokens[enpin].type==S){
                        int newpin = enpin+1;
                        std::string fullstr;
                        while(newpin<tokens.size()&&tokens[newpin].type!=S){
                            fullstr += tokens[newpin].value;
                            newpin++;
                        }
                        uint64_t str_ptr = getstrreg(intoLib, fullstr);
                        switch(wholisten){
                            case 1 : intoLib.rax= str_ptr;break;
                            case 2 : intoLib.rdi= str_ptr;break;
                            case 3 : intoLib.rsi= str_ptr;break;
                            case 4 : intoLib.rdx= str_ptr;break;
                            case 5 : intoLib.r10= str_ptr;break;
                            case 6 : intoLib.r8=  str_ptr;break;
                            case 7 : intoLib.r9=  str_ptr;break;
                        }
                        enpin=newpin+1;
                    }
                    else if(tokens[enpin].type==SS){
                        int newpin = enpin+1;
                        std::string fullstr;
                        while(newpin<tokens.size()&&tokens[newpin].type!=SS){
                            fullstr += tokens[newpin].value;
                            newpin++;
                        }
                        uint64_t str_ptr = getstrreg(intoLib, fullstr);
                        switch(wholisten){
                            case 1 : intoLib.rax= str_ptr;break;
                            case 2 : intoLib.rdi= str_ptr;break;
                            case 3 : intoLib.rsi= str_ptr;break;
                            case 4 : intoLib.rdx= str_ptr;break;
                            case 5 : intoLib.r10= str_ptr;break;
                            case 6 : intoLib.r8=  str_ptr;break;
                            case 7 : intoLib.r9=  str_ptr;break;
                        }
                        enpin=newpin+1;
                    }

                }

                enpin++;
            }
            return ASM_Exec(intoLib);

        }

    };


    class HexExecutor : rmc {
        public:
            static void executeHex(const std::string& hexStr) { try{rmc::run(hexStr);}catch(...){LOG::fkr("HR","el kair ");} }
        };
        
    
};


#include "ps.hpp"
