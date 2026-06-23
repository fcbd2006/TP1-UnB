#include "ControladorasA/Headers/cai.hpp"
#include "ControladorasA/Headers/cac.hpp"
#include "ControladorasA/Headers/cagh.hpp"
#include "ControladorasA/Headers/cagp.hpp"
#include "ControladorasA/Headers/caa.hpp"
#include "ControladorasS/Headers/cservico.hpp"

using namespace std;

int main()
{
    CntrIAInicial programa;
    CntrIAAutenticacao auth;
    CntrIACadastro cad;
    CntrIAGestaoHistorias hist;
    CntrIAGestaoProjetos proj;
    auth.setServicoAutenticacao(new CntrISAutenticacao);
    cad.setServicoCadastro(new CntrISCadastro);
    hist.setServicoGestaoHistorias(new CntrISGestaoHistorias);
    proj.setServicoGestaoProjetos(new CntrISGestaoProjetos);
    programa.setApresentacaoAutenticacao(&auth);
    programa.setApresentacaoCadastro(&cad);
    programa.setApresentacaoHistorias(&hist);
    programa.setApresentacaoProjetos(&proj);

    programa.executar();

    return 0;
}
