
const std::set<char> spec_sims = {'$','?','!','=','/','#', '~', ':' ,'.',',', '\'' ,'"' , '(', ')' , '[' , ']' , '{' , '}' , '<' , '>' , '_',' ','-','+','*', '@', '\n' , ';' };

enum TSID{
    TRIG,
    VA, NDEK, DEZ,
    SY, DREB, DYR, TAK,
    BEDTAK, STRING, INT, INGOR, ZCEL,
    CYI,
    S, SS,
    PE, PU,
    DE, DU,
    GE, GU,
    CE, CU,
    DIG,TAB,
    SI,SPI,
    ZIG,
    LINK,
    FATER
};

struct TOKENS{
    TSID  type;
    std::string value;  
};

class SIMS{
public:
    static char get_sim_from_name(TSID sname){
        switch(sname){
            case TSID::TRIG:   return SIMS::TRIG;
            case TSID::VA:     return SIMS::VA;
            case TSID::DEZ:    return SIMS::DEZ;
            case TSID::NDEK:   return SIMS::NDEK;
            case TSID::DYR:    return SIMS::DYR;
            case TSID::SY:     return SIMS::SY;
            case TSID::DREB:   return SIMS::DREB;
            case TSID::BEDTAK: return SIMS::BEDTAK;
            case TSID::TAK:    return SIMS::TAK;
            case TSID::CYI:    return SIMS::CYI;
            case TSID::S:      return SIMS::S;
            case TSID::SS:     return SIMS::SS;  
            case TSID::PE:     return SIMS::PE;
            case TSID::PU:     return SIMS::PU;
            case TSID::DE:     return SIMS::DE;
            case TSID::DU:     return SIMS::DU;
            case TSID::GE:     return SIMS::GE;
            case TSID::GU:     return SIMS::GU;
            case TSID::CE:     return SIMS::CE;
            case TSID::CU:     return SIMS::CU;
            case TSID::DIG:    return SIMS::DIG;
            case TSID::TAB:    return SIMS::TAB;
            case TSID::ZIG:    return SIMS::ZIG;
            case TSID::SI:     return SIMS::SI;
            case TSID::SPI:    return SIMS::SPI;
            case TSID::INGOR:  return SIMS::INGOR;
            case TSID::ZCEL:   return SIMS::ZCEL;

            default:           return 0;
        }
    }
    
    static TSID get_name_from_sim(char c){
        switch (c){
            case SIMS::TRIG:   return TSID::TRIG;
            case SIMS::VA:     return TSID::VA;
            case SIMS::DEZ:    return TSID::DEZ;
            case SIMS::NDEK:   return TSID::NDEK;
            case SIMS::DYR:    return TSID::DYR;
            case SIMS::SY:     return TSID::SY;
            case SIMS::DREB:   return TSID::DREB;
            case SIMS::BEDTAK: return TSID::BEDTAK;
            case SIMS::TAK:    return TSID::TAK;
            case SIMS::CYI:    return TSID::CYI;
            case SIMS::S:      return TSID::S;
            case SIMS::SS:     return TSID::SS;
            case SIMS::PE:     return TSID::PE;
            case SIMS::PU:     return TSID::PU;
            case SIMS::DE:     return TSID::DE;
            case SIMS::DU:     return TSID::DU;
            case SIMS::GE:     return TSID::GE;
            case SIMS::GU:     return TSID::GU;
            case SIMS::CE:     return TSID::CE;
            case SIMS::CU:     return TSID::CU;
            case SIMS::DIG:    return TSID::DIG;
            case SIMS::TAB:    return TSID::TAB;
            case SIMS::LINK:   return TSID::LINK;
            case SIMS::ZIG:    return TSID::ZIG;
            case SIMS::SI:     return TSID::SI;
            case SIMS::SPI:    return TSID::SPI;
            case SIMS::INGOR:  return TSID::INGOR;
            case SIMS::ZCEL:   return TSID::ZCEL;
        }
        return TSID::FATER;
    }
    
    static std::string get_sname_from_sim(char c){
        switch (c){
            case SIMS::TRIG:   return "<TRIG>";
            case SIMS::VA:     return "<VA>";
            case SIMS::DEZ:    return "<DEZ>";
            case SIMS::NDEK:   return "<NDEK>";
            case SIMS::DYR:    return "<DYR>";
            case SIMS::SY:     return "<SY>";
            case SIMS::DREB:   return "<DREB>";
            case SIMS::BEDTAK: return "<BEDTAK>";
            case SIMS::TAK:    return "<TAK>";
            case SIMS::CYI:    return "<CYI>";
            case SIMS::S:      return "<S>";
            case SIMS::SS:     return "<SS>";
            case SIMS::PE:     return "<PE>";
            case SIMS::PU:     return "<PU>";
            case SIMS::DE:     return "<DE>";
            case SIMS::DU:     return "<DU>";
            case SIMS::GE:     return "<GE>";
            case SIMS::GU:     return "<GU>";
            case SIMS::CE:     return "<CE>";
            case SIMS::CU:     return "<CU>";
            case SIMS::DIG:    return "<DIG>";
            case SIMS::TAB:    return "<TAB>";
            case SIMS::LINK:   return "<LINK>";
            case SIMS::ZIG:    return "<ZIG>";
            case SIMS::SI:     return "<SI>";
            case SIMS::SPI:    return "<SPI>";
            case SIMS::INGOR:  return "<INGOR>";
            case SIMS::ZCEL:   return "<ZCEL>";        }
        return "<FATER>";
    }
    static std::string get_sname_from_name(TSID t){
        switch (t){
            case TSID::TRIG:   return "[TRIG]";
            case TSID::VA:     return "[VA]";
            case TSID::DEZ:    return "[DEZ]";
            case TSID::NDEK:   return "[NDEK]";
            case TSID::DYR:    return "[DYR]";
            case TSID::SY:     return "[SY]";
            case TSID::DREB:   return "[DREB]";
            case TSID::BEDTAK: return "[BEDTAK]";
            case TSID::TAK:    return "[TAK]";
            case TSID::CYI:    return "[CYI]";
            case TSID::S:      return "[S]";
            case TSID::SS:     return "[SS]";  
            case TSID::PE:     return "[PE]";
            case TSID::PU:     return "[PU]";
            case TSID::DE:     return "[DE]";
            case TSID::DU:     return "[DU]";
            case TSID::GE:     return "[GE]";
            case TSID::GU:     return "[GU]";
            case TSID::CE:     return "[CE]";
            case TSID::CU:     return "[CU]";
            case TSID::DIG:    return "[DIG]";
            case TSID::TAB:    return "[TAB]";
            case TSID::LINK:   return "[LINK]";
            case TSID::ZIG:    return  "[ZIG]";
            case TSID::SI:     return  "[SI]";
            case TSID::SPI:    return  "[SPI]";
            case TSID::INGOR:  return "[INGOR]";
            case TSID::ZCEL:   return "[ZCEL]";

            case TSID::STRING: return "[STRING]";
            case TSID::INT:    return "[INT]";
            case TSID::FATER:  return "[FATER]";

        
        }
    }
    static bool is_special_char(char s) {return spec_sims.find(s) != spec_sims.end();}
    const static char TRIG   = '$';
    const static char VA     = '?';
    const static char DEZ    = '!';    
    const static char NDEK   = '=';
    const static char SY     = '~';
    const static char DYR    = '/';
    const static char DREB   = '#';
    const static char BEDTAK = ':';
    const static char TAK    = '.';
    const static char CYI    = ',';
    const static char S      = '\'';
    const static char SS     = '"';
    const static char PE     = '(';
    const static char PU     = ')';
    const static char DE     = '[';
    const static char DU     = ']';
    const static char GE     = '{';
    const static char GU     = '}';
    const static char CE     = '<';
    const static char CU     = '>';
    const static char DIG    = '_';
    const static char TAB    = ' ';
    const static char SI     = '-';
    const static char SPI    = '+';
    const static char LINK   = '@';
    const static char ZIG    = '*';
    const static char INGOR  = '\n';
    const static char ZCEL   = ';';
};
std::vector<TOKENS> tokenizer(std::string& content) {
    std::vector<TOKENS> return_data;
    std::stringstream sims(content);
    while(sims.peek() != EOF) {
        char sim = sims.peek();
        
        if (SIMS::is_special_char(sim)) {
            sims.get();
            TSID type = SIMS::get_name_from_sim(sim);
            return_data.push_back({type, std::string(1, sim)});
        }
        else {
            char c = sims.get();
            if (isalpha(c)) return_data.push_back({TSID::STRING, std::string(1, c)});
            else if (isdigit(c)) return_data.push_back({TSID::INT, std::string(1, c)});
            else return_data.push_back({TSID::FATER, std::string(1, c)});

        }
    }
    return return_data;
}
