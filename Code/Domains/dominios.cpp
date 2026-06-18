#include <Domains/Headers/outros_dominios.hpp>
#include <stdexcept>
#include <cctype>

// CODIGO

// Método para validação do formato de valor a ser armazenado no domínio Código
// AA000
void Codigo::validar(const std::string& codigo){

    // verifica o comprimento da string
    if((int)codigo.size() != 5) throw std::invalid_argument("Valor Inválido para Código -> Número de caracteres diferente de 5");
    
    // verifica se os 2 primeiros caracteres são letras maiusculas
    for(int index=0;index<=1;index++){
        if(!isupper(codigo[index])) throw std::invalid_argument("Valor Inválido para Código -> 2 primeiros caracteres não condizem");
    }

    // verifica se os 3 ultimos caracteres são números
    for(int index=2;index<=4;index++){
        if(!isdigit(codigo[index])) throw std::invalid_argument("Valor Inválido para Código -> 3 últimos caracteres não condizem");
    }
}

//-----------------------------------------------------------

// DATA

// Método para validação do formato de valor a ser armazenado no domínio Data
// DD/MM/YYYY
void Data::validar(const std::string& data){
    // verifica comprimento da string para que seja do formato
    if(data.size()!=10) throw std::invalid_argument("Valor Inválido para Data -> Comprimento Invalido");

    // verifica posição das barras
    if(data[2]!='/' || data[5]!='/') throw std::invalid_argument("Valor Inválido para Data -> Formato não condiz");

    // verifica se todos os caracteres são dígitos
    for(int index=0;index < int (data.size());index++){
        // pula as barras
        if(index==2||index==5) continue;

        if(!isdigit(data[index])) throw std::invalid_argument("Valor Inválido para Data -> Caractere inválido");
    }

    // substring para cada parte da data e transforma em um int
    int dia = stoi(data.substr(0,2));
    int mes = stoi(data.substr(3,2));
    int ano = stoi(data.substr(6,4));

    // verifica o mes
    if(mes>12 || mes<1) throw std::invalid_argument("Valor Inválido para Data -> Mês inválido");

    //verifica o ano
    if(ano>2999 || ano<2000) throw std::invalid_argument("Valor Inválido para Data -> Ano inválido");

    // Arrays com qnts dias tem cada mes
    int diasMensais[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    // mes 2 tem mais dias se for bissexto, ent se tiver trabalhando com esse caso, altera
    if(mes==2 && ehBisexto(ano)) diasMensais[2]=29;
    
    // verifica o dia
    if(!(dia>0 && dia<=diasMensais[mes])) throw std::invalid_argument("Valor Inválido para Data -> Dia inválido");
}

//-----------------------------------------------------------

// EMAIL

// Método para validação do formato de valor a ser armazenado no domínio Email
// string@string
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
void Email::validar_formato(const std::string& parte) const{
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

//----------------------------------------------------------

// ESTADO

// Método para validação do formato de valor a ser armazenado no domínio Estado
// "A FAZER", "FAZENDO", ou "FEITO"
void Estado::validar(const std::string& estado){
    if(!(estado=="A FAZER" || estado=="FAZENDO" || estado=="FEITO")) throw std::invalid_argument("Valor Inválido para Estado.");
}

//-----------------------------------------------------------

// NOME

// Método para validação do formato de valor a ser armazenado no domínio Nome
// 10 caracteres, " ", a-z, A-Z
void Nome::validar(const std::string& nome){
    // verifica o tamanho
    if(nome.size()>10) throw std::invalid_argument("Valor Inválido para Nome -> Longo demais");

    // verifica se o primeiro ou ultimo caracteres sao espaços
    if(nome[0]==' ' || nome[nome.size()-1]==' ') throw std::invalid_argument("Valor Inválido para Nome -> Espaço no início ou final");
    
    // verifica cada caracter
    
    for(int index=0;index<int(nome.size());index++){
        
        // verifica se é letra dps de cada espaço
        if(nome[index]==' ' && !isalpha(nome[index+1]))
            throw std::invalid_argument("Valor Inválido para Nome -> Espaço duplicado");
        
        // verifica se algum caracter não é letra ou ' '
        if(!(isalpha(nome[index]) || nome[index]!=' '))
            throw std::invalid_argument("Valor Inválido para Nome -> Caractere inválido");
    }
}

//-----------------------------------------------------------

// PAPEL

// Método para validação do formato de valor a ser armazenado no domínio Papel
// "DESENVOLVEDOR", "MESTRE SCRUM", ou "PROPRIETARIO DE PRODUTO"
void Papel::validar(const std::string& papel){
    if(!(papel=="DESENVOLVEDOR" || papel=="MESTRE SCRUM" || papel=="PROPRIETARIO DE PRODUTO")) throw std::invalid_argument("Valor Inválido para Papel.");
}

//-----------------------------------------------------------

// PRIORIDADE

// Método para validação do formato de valor a ser armazenado no domínio Prioridade
// "ALTA", "MEDIA", ou "BAIXA"
void Prioridade::validar(const std::string& prioridade){
    if(!(prioridade=="ALTA" || prioridade=="MEDIA" || prioridade=="BAIXA")) throw std::invalid_argument("Valor Inválido para Prioridade.");
}

//-----------------------------------------------------------

// SENHA

// Método para validação do formato de valor a ser armazenado no domínio Senha
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

//-----------------------------------------------------------

// TEMPO

// Método para validação do formato de valor a ser armazenado no domínio Tempo
// 1 a 365
void Tempo::validar(const std::string& tempo){
    // verifica se tem de 1 a 3 caracteres
    if(tempo.size()>3) throw std::invalid_argument("Valor Inválido para Tempo -> Excede tamanho");

    // verifica se todos os caracteres são dígitos
    for(auto& c : tempo){
        if(!isdigit(c)) throw std::invalid_argument("Valor Inválido para Tempo -> Deve ser números");
    }

    // transforma a string em int e verifica se faz parte do intervalo aceito
    int a = stoi(tempo);
    if(a<1 || a>365) throw std::invalid_argument("Valor Inválido para Tempo -> Fora do intervalo");
}

//-----------------------------------------------------------

// TEXTO

// Método para validação do formato de valor a ser armazenado no domínio Texto
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

//-----------------------------------------------------------