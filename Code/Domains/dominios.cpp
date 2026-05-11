#include <Domains/Headers/outros_dominios.hpp>
#include <stdexcept>
#include <cctype>

// CODIGO
void Codigo::validar(const std::string& codigo){
    for(int index=0;index<=1;index++){
        if(codigo[index]<'A' || codigo[index]>'Z') throw std::invalid_argument("Valor Inválido para Código.");
    }    
    for(int index=2;index<=4;index++){
        if(codigo[index]<'0' || codigo[index]>'9') throw std::invalid_argument("Valor Inválido para Código.");
    }
}
////////////////////////////////////////////////////////////////

// DATA
void Data::validar(const std::string& data){
    if(data.size()!=10) throw std::invalid_argument("Valor Inválido para Data.");
    if(data[2]!='/' || data[5]!='/') throw std::invalid_argument("Valor Inválido para Data.");
    for(int index=0;index<= int (data.size());index++){
        if(index==2||index==5) continue;
        if(data[index]<'0' || data[index]>'9') throw std::invalid_argument("Valor Inválido para Data.");
    }
    int dia = stoi(data.substr(0,2));
    int mes = stoi(data.substr(3,2));
    int ano = stoi(data.substr(6,4));

    if(mes>12 || mes<1) throw std::invalid_argument("Valor Inválido para Data.");
    if(ano>2999 || ano<2000) throw std::invalid_argument("Valor Inválido para Data.");

    int diasMensais[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    if(mes==2 && ehBisexto(ano)) diasMensais[2]=29;
    
    if(!(dia>0 && dia<=diasMensais[mes])) throw std::invalid_argument("Valor Inválido para Data.");
}
////////////////////////////////////////////////////////////////

// EMAIL
void Email::validar(const std::string& email){
    //Encontrar a posição do '@' e garantir que não está nos extremos.
    size_t position = email.find('@');
    if(position == std::string::npos || position == 0 || position == email.length() -1){
        throw std::invalid_argument("Valor Inválido para Email.");
    }

    //Separação do email em local e domínio.
    std::string local = email.substr(0, position);
    std::string dominio = email.substr(position + 1);

    //Conferir comprimentos máximos.
    if(local.length() > 64 || dominio.length() > 255){
        throw std::invalid_argument("Valor Inválido para Email.");
    }
    
    //Validação das partes do email por meio da função validar_formato.
    validar_formato(local);
    validar_formato(dominio);
}

//Função auxiliar para validar as partes do email.
void Email::validar_formato(const std::string& parte){
    if(parte.front() == '.' || parte.front() == '-' || parte.back() == '.' || parte.back() == '-'){
        throw std::invalid_argument("Valor Inválido para  Email.");
    }

    for(size_t i = 0; i < parte.length(); i++){
        char c = parte[i];

        if(!isalnum(c) && c != '.' && c != '-'){
            throw std::invalid_argument("Valor Inválido para Email.");
        }

        if((c == '.' || c == '-') && i + 1 < parte.length()){
            char proximo = parte[i + 1];
            if(proximo == '.' || proximo == '-'){
                throw std::invalid_argument("Valor Inválido para Email.");
            }
        }
    }
}

////////////////////////////////////////////////////////////////

// ESTADO
void Estado::validar(const std::string& estado){
    if(!(estado=="A FAZER" || estado=="FAZENDO" || estado=="FEITO")) throw std::invalid_argument("Valor Inválido para Estado.");
}

////////////////////////////////////////////////////////////////

// NOME
void Nome::validar(const std::string& nome){
    if(nome.size()>10) throw std::invalid_argument("Valor Inválido para Nome.");
    if(nome[0]==' ' || nome[nome.size()-1]==' ') throw std::invalid_argument("Valor Inválido para Nome.");
    for(int index=0;index<=(int(nome.size())-1);index++){

        if(nome[index]==' ' && ((nome[index+1]<'A' || nome[index+1]>'Z') && (nome[index+1]<'a' || nome[index+1]>'z')))
            throw std::invalid_argument("Valor Inválido para Nome.");
    
        if((nome[index]<'A' || nome[index]>'Z') && (nome[index]<'a' || nome[index]>'z') && nome[index]!=' ')
            throw std::invalid_argument("Valor Inválido para Nome.");
    }
}

////////////////////////////////////////////////////////////////

// PAPEL
void Papel::validar(const std::string& papel){
    if(!(papel=="DESENVOLVEDOR" || papel=="MESTRE SCRUM" || papel=="PROPRIETARIO DE PRODUTO")) throw std::invalid_argument("Valor Inválido para Papel.");
}

////////////////////////////////////////////////////////////////

// PRIORIDADE
void Prioridade::validar(const std::string& prioridade){
    if(!(prioridade=="ALTA" || prioridade=="MEDIA" || prioridade=="BAIXA")) throw std::invalid_argument("Valor Inválido para Prioridade.");
}

////////////////////////////////////////////////////////////////

// SENHA
void Senha::validar(const std::string& senha){
    //Verificar tamanho.
    if(senha.length() != 6){
        throw std::invalid_argument("Valor Inválido para Senha.");
    }

    //Variáveis para verificar a presença de maiúsculas, minúsculas e dígitos.
    bool tem_maiuscula = false;
    bool tem_minuscula = false;
    bool tem_digito = false;

    //Verificar regras de formatação da senha.
    for(size_t i = 0; i < senha.length(); i++){
        char c = senha[i];

        if(isupper(c)){
            tem_maiuscula = true;
        }
        else if(islower(c)){
            tem_minuscula = true;
        }
        else if(isdigit(c)){
            tem_digito = true;
        }
        else{
            throw std::invalid_argument("Valor Inválido para Senha.");
        }
        //Garante a não repetição de caracteres.
        if(senha.find(c, i+1) != std::string::npos){
            throw std::invalid_argument("Valor Inválido para Senha.");
        }

        if(i > 0){
            if((isalpha(senha[i - 1]) && isalpha(c)) || (isdigit(senha[i - 1]) && isdigit(c))){
                throw std::invalid_argument("Valor Inválido para Senha.");
            }
        }
    }
    //Verificar se a senha contém pelo menos um caractere de cada tipo.
    if(!tem_maiuscula || !tem_minuscula || !tem_digito){
        throw std::invalid_argument("Valor Inválido para Senha.");
    }
}

////////////////////////////////////////////////////////////////

// TEMPO
void Tempo::validar(const std::string& tempo){
    if(tempo.size()>3) throw std::invalid_argument("Valor Inválido para Tempo.");
    for(auto c : tempo){
        if(c<'0'|| c>'9') throw std::invalid_argument("Valor Inválido para Tempo.");
    }
    int a = stoi(tempo);
    if(a<1 || a>365) throw std::invalid_argument("Valor Inválido para Tempo.");
}
////////////////////////////////////////////////////////////////

// TEXTO
void Texto::validar(const std::string& texto){
    //Verificar comprimento e se é vazio.
    if(texto.empty() || texto.length() > 40){
        throw std::invalid_argument("Valor Inválido para Texto.");
    }
    //Verificar o primeiro caractere.
    if(texto.front() == ' ' || texto.front() == ',' || texto.front() == '.'){
        throw std::invalid_argument("Valor Inválido para Texto.");
    }
    //Verificar o último caractere.
    if(texto.back() == ' ' || texto.back() == ',' || texto.back() == '.'){
        throw std::invalid_argument("Valor Inválido para Texto.");
    }
    //Verificar caracteres e duplicatas.
    for(size_t i = 0; i < texto.length(); i++){
        char c = texto[i];

        if(!isalnum(c) && c != ' ' && c != ',' && c != '.'){
            throw std::invalid_argument("Valor Inválido para Texto.");
        }

        if(i > 0){
            char anterior = texto[i - 1];
            if((c == ' ' || c == ',' || c == '.') && (anterior == ' ' || anterior == ',' || anterior == '.')){
                throw std::invalid_argument("Valor Inválido para Texto.");
            }
        }
    }
}

////////////////////////////////////////////////////////////////