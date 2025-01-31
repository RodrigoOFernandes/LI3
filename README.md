# LI3 - Sistema de Análise de Dados de Música

Este projeto foi desenvolvido no âmbito da unidade curricular de Laboratórios de Informática III e consiste num sistema de processamento e análise de dados musicais utilizando a biblioteca GLib.

## 📜 Descrição

O LI3 é um programa em C que processa e analisa um conjunto de ficheiros CSV contendo informações sobre:

- 🎵 Músicas  
- 👤 Utilizadores  
- 📜 Histórico de reprodução  
- 🎼 Géneros musicais  

Após validar os dados, o sistema armazena as informações em **GHashTables** (GLib) e permite a execução de diversas **queries**, como:

- Determinar o género musical mais apreciado numa determinada faixa etária  
- Analisar padrões de reprodução dos utilizadores  
- Consultar estatísticas sobre músicas e utilizadores  

Além disso, o sistema inclui três modos de execução:

- **Modo Interativo** → Permite ao utilizador introduzir queries manualmente  
- **Modo Normal** → Processa os ficheiros e executa operações predefinidas  
- **Modo de Testes** → Mede o desempenho em termos de **uso de CPU, memória e tempo de execução**  
