# Power_supply_meter
## Projeto: Fonte de Bancada Ajustável com medição via LCD 20x4

### Descrição
Este projeto é sobre uma fonte de bancada ajustável, capaz de fornecer tensões de 0 a 30V e correntes de até 4A, com leitura em tempo real de tensão, corrente e potência. A fonte em sí trata-se de um projeto open source e não será abordada aqui.



O sistema de medição está sendo desenvolvido na plataforma arduino. Ele utiliza um digispark para se comunicar com um lcd 20x4 e exibir os dados coletados, Tensão, corrente ( Através do sensor ACS712 ) e a potencia calculada na carga.

### Hardware Utilizado
Microcontrolador: Arduino Mega (para prototipagem) e Digispark (para versão final)
Display: LCD 20x4 I2C
Sensor de Corrente: ACS712 (30A)
Placa open source - fonte de bancada com controle de tensão e corrente:

![D_NQ_NP_924345-MLB31871849386_082019-O](https://github.com/user-attachments/assets/f95455fc-2772-4e2c-8927-731ed8a078b4)
![D_NQ_NP_804801-MLB43726908597_102020-O](https://github.com/user-attachments/assets/e5b3c0b2-4795-4e04-911e-d04e1628d94a)


Gabinete: Adaptado com espaço para knobs de controle de ajuste fino, conectores banana para fácil conexão, e um painel frontal para visualização do display LCD.
Dissipadores e coolers.

### Funcionalidades
Modo de Operação: Tensões ajustáveis de 0-30V e correntes de 0-4A.
Leitura de Parâmetros: O sistema exibe a tensão, corrente e potência calculada em tempo real.


#

# Em algum momento eu coloco mais fotos e atualizações desse projeto. O proposito maior aqui é organizar esse codigo para o Gabriel do Futuro.
