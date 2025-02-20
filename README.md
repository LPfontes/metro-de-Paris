![image](https://github.com/user-attachments/assets/8b61d6fd-2dd1-41e7-8f61-718efbd6e3a0) (Fonte CGI/CIn/UFPE) Problema do metrô de Paris
Suponha que queremos construir um sistema para auxiliar um usuário do metrô de
Paris a saber o trajeto mais rápido entre a estação onde ele se encontra e a estação de
destino. O usuário tem um painel com o mapa, podendo selecionar a sua estação de
destino. O sistema então acende as luzes sobre o mapa mostrando o melhor trajeto a
seguir (em termos de quais estações ele vai atravessar., e quais as conexões mais
rápidas a fazer – se for o caso).
Considere que:
• a distância em linha reta entre duas estações quaisquer é dada em uma tabela. Para
facilitar a vida, considere apenas 4 linhas do metrô.
• a velocidade média de um trem é de 30km/h;
• tempo gasto para trocar de linha dentro de mesma estação (fazer baldeação) é de 4
minutos.
Formule e implemente este problema para o estado inicial E1, e estado final E12 para
busca heurística com A*. Defina a função de avaliação.
