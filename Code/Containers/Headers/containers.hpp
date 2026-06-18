#ifndef CONTAINERS_HPP_INCLUDED
#define CONTAINERS_HPP_INCLUDED

#include "Entities/Headers/entidades.hpp"
#include <map>
#include <string>

/**
 * @brief Classe genérica para armazenar e gerenciar pares de chave e valor.
 * * Esta classe utiliza um std::map internamente para armazenar os dados, 
 * o que garante que as chaves sejam únicas e permite operações de busca,
 * inserção, remoção e atualização eficientes.
 * * @tparam K O tipo de dado utilizado para a chave.
 * @tparam V O tipo de dado utilizado para o valor (item) associado à chave.
 */
template <typename K, typename V>
class Container {
    private:
        /**
         * @brief Construtor padrão privado.
         * * Ocultado para impedir a criação de instâncias da classe de forma 
         * direta garantindo, assim, o padrão Singleton.
         */
        Container() = default;

        /**
         * @brief Destrutor padrão privado.
         * * Ocultado para impedir que a instância única seja destruída manualmente.
         */
        ~Container() = default;

        /**
         * @brief Contêiner interno do tipo mapa que armazena os dados.
         */
        std::map<K, V> container;

    public:
        /**
         * @brief Construtor de cópia deletado para garantir o padrão Singleton.
         * * Impede que a instância do contêiner seja copiada acidentalmente. 
         * Isso é fundamental para o padrão Singleton, pois garante que 
         * nunca existirá mais de um objeto deste tipo em memória.
         */
        Container(const Container&) = delete;

        /**
         * @brief Operador de atribuição deletado para garantir o padrão Singleton.
         * * Evita que o estado da instância única seja sobrescrito ou atribuído 
         * através do operador de igualdade (=), mantendo a integridade da instância.
         */
        Container& operator=(const Container&) = delete;

        /**
         * @brief Obtém a instância única e global do contêiner.
         * * Este método é o único ponto de acesso ao contêiner. A instância é 
         * criada apenas na primeira vez em que esta função é chamada.
         * * @return Container& Referência para a instância única do contêiner.
         */
        static Container& getInstance(){
            static Container instance;
            return instance;
        }

        /**
         * @brief Inclui um novo item no contêiner.
         * * @param chave A chave identificadora do item a ser incluído.
         * @param item O valor do item a ser armazenado.
         * @return true Se o item foi incluído com sucesso.
         * @return false Se já existir um item com a mesma chave no contêiner.
         */
        bool criar(const K& chave, const V& item);

        /**
         * @brief Remove um item do contêiner com base na sua chave.
         * * @param chave A chave do item que se deseja remover.
         * @return true Se o item foi encontrado e removido com sucesso.
         * @return false Se a chave não for encontrada no contêiner.
         */
        bool excluir(const K& chave);

        /**
         * @brief Pesquisa por um item no contêiner utilizando a sua chave.
         * * Se a chave for encontrada, o valor associado a ela será copiado para
         * o endereço de memória apontado pelo parâmetro `item`.
         * * @param chave A chave do item a ser pesquisado.
         * @param item Ponteiro onde o valor encontrado será armazenado.
         * @return true Se a chave for encontrada no contêiner.
         * @return false Se a chave não for encontrada.
         */
        bool ler(const K& chave, V& item); 

        /**
         * @brief Atualiza o valor de um item existente no contêiner.
         * * @param chave A chave do item que terá seu valor atualizado.
         * @param item O novo valor que substituirá o valor antigo.
         * @return true Se o item foi encontrado e atualizado com sucesso.
         * @return false Se a chave não for encontrada no contêiner.
         */
        bool atualizar(const K& chave, const V& item);
};

template <typename K, typename V>
bool Container<K, V>::criar(const K& chave, const V& item) {
    // map::insert tenta inserir o par (chave, valor).
    // Ele retorna um par onde o 'second' é um bool indicando se a inserção ocorreu.
    // Retornará false se a chave já existir no mapa.
    auto resultado = container.insert({chave, item});
    return resultado.second; 
}

template <typename K, typename V>
bool Container<K, V>::excluir(const K& chave) {
    // map::erase remove o elemento pela chave e retorna a quantidade de itens removidos.
    // Como chaves no map são únicas, retornará 1 (sucesso) ou 0 (falha/não encontrado).
    return container.erase(chave) > 0;
}

template <typename K, typename V>
bool Container<K, V>::ler(const K& chave, V& item) {
    // map::find busca a chave e retorna um iterador.
    auto it = container.find(chave);
    
    // Compara com map::end() para checar se encontrou algo
    if (it != container.end()) {
        item = it->second; 
        return true;
    }
    return false;
}

template <typename K, typename V>
bool Container<K, V>::atualizar(const K& chave, const V& item) {
    auto it = container.find(chave);
    
    // Só atualizamos se o elemento já existir (para não criar acidentalmente)
    if (it != container.end()) {
        it->second = item;
        return true;
    }
    return false;
}

#endif // CONTAINERS_HPP_INCLUDED