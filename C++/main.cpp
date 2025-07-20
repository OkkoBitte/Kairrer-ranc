#include "kairrer/lintkrr.hpp"
int main(int argc, char* argv[]) {
    std::string code;
    if (argc < 2) std::cout<<"lint --gal"<<std::endl;
    else if (argc >= 2) {
        auto marg=std::string(argv[1]) ;
        
        if (marg == "--gal" || marg == "-gal"  || marg == "--g"  || marg== "-g") {
            std::cout << "|[KRR][GAL]|[ "<<std::endl<<cyan<<"\t" << argv[0] << " <filename>.kr"<<reset<<std::endl<<" ]"<<std::endl
            <<std::endl<<"\t"<<cyan<<argv[0] <<" --v "<<reset<<" rail liber"<<std::endl
            
            <<std::endl<<"[MBG]"<<std::endl;
            return 0;
        }
        else if(marg =="--vocem" || marg == "-vocem" || marg == "--v" || marg == "-v" ){
            std::cout<< "|[KRR][VOCEM]|"<<std::endl<<"Version Code " <<VERSION_CODE__KRR << std::endl<<
            "Version Name " <<VERSION_NAME__KRR<< std::endl<< "Version Type "<< VERISON_TYPE__KRR<< std::endl<<std::endl<<
            "More " << "https://web-mbg.ru"<<std::endl;
            return 0;
        }
        else{
            std::string filename = marg;
            if (!file::is_file(filename)){
                std::cerr << red<< "|[KAIRRER] wapin file? et-> " << filename <<reset << std::endl;
                return 1;
            }
            
            code = file::read_file<std::string>(marg);


        }
        

    }
    
    std::vector<std::string> args;
    for(int a=0;a<argc;a++)args.push_back(argv[a]);
    
    vars return_data=kairrer(code, args);
    
    if (return_data.valib.type==VSID::intV) return atoi(return_data.valib.value.c_str());
    else return 0;
    

}