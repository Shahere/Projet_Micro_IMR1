
#include "lpc17xx_i2c.h"

//===========================================
// initialisation de la mémoire i2c
//===========================================
void init_i2c_eeprom() {
	I2C_Init(LPC_I2C0, 100000);
	I2C_Cmd(LPC_I2C0, ENABLE);
}

//===========================================
// Ecriture dans la mémoire i2c
//===========================================
void i2c_eeprom_write(uint16_t addr, void* data, int length) {
	I2C_M_SETUP_Type i2cSetup;
	
	i2cSetup.sl_addr7bit = 0x51;
	i2cSetup.tx_data = data;
  i2cSetup.tx_length = length;
  i2cSetup.rx_data = NULL;
  i2cSetup.rx_length = 0;
  i2cSetup.retransmissions_max = 10;
	i2cSetup.callback = NULL;
	
	I2C_MasterTransferData(LPC_I2C0, &i2cSetup, I2C_TRANSFER_POLLING);
}

//===========================================
// Lecture dans la mémoire i2c
//===========================================
Status i2c_eeprom_read(uint8_t addr, void* data_recup, int length) {
    I2C_M_SETUP_Type setupi2c;
    
    setupi2c.sl_addr7bit = 0x51; 
    setupi2c.tx_data = &addr; // on se pointe sans rien ecrire
    setupi2c.tx_length = length;	// avec que 1 de len
    setupi2c.rx_data = NULL;	// on se pointe pareil mais en mode ecriture
    setupi2c.rx_length = 0;	// on lit que 1 data
    setupi2c.retransmissions_max = 10;
		setupi2c.callback = NULL;
    
     I2C_MasterTransferData(LPC_I2C0, &setupi2c, I2C_TRANSFER_POLLING);
	
    setupi2c.tx_data = NULL; // on se pointe sans rien ecrire
    setupi2c.tx_length = 0;	// avec que 1 de len
    setupi2c.rx_data = data_recup;	// on se pointe pareil mais en mode ecriture
    setupi2c.rx_length = length;	// on lit que 1 data
    
    I2C_MasterTransferData(LPC_I2C0, &setupi2c, I2C_TRANSFER_POLLING);
}

