#ifndef ROBOT_H
#define ROBOT_H

#include "Fonctions.h"

class Robot
{
public:
	Robot();

	void moteurOn(bool gauche = true, bool droite = true);
	void moteurOnG(bool gauche = true);
	void moteurOnD(bool droite = true);

	void moteurAvant(bool gauche = true, bool droite = true);
	void moteurAvantG(bool gauche = true);
	void moteurAvantD(bool droite = true);
	
	void moteurVitesse(int vitesseG, int vitesseD);
	void moteurVitesseG(int vitesseG);
	void moteurVitesseD(int vitesseD);

	bool CapteurArriere(const unsigned int delaiTest);
	bool CapteurGauche(const unsigned int delaiTest);
	bool CapteurDroit(const unsigned int delaiTest);

	void Test(void);

	inline static void putON(volatile uint8_t &port, const uint8_t &bit);
	inline static void putOFF(volatile uint8_t &port, const uint8_t &bit);


	static volatile uint8_t &m_ledLPort;
	static const uint8_t &m_ledLBit;

private:

	void InitPort(void);
	void InitPWM(void);

	void MoteurGauche(int iAlpha, bool bSens);
	void MoteurDroit(int iAlpha, bool bSens);


	// Variables permettant de connaitre l'�tat des moteurs
	bool m_moteurOnG;
	bool m_moteurOnD;
	bool m_moteurAvantG;
	bool m_moteurAvantD;
	int m_moteurVitesseG; // vitesse entre 0 et 100
	int m_moteurVitesseD;


	bool m_etatCaptIRArr;
	bool m_etatCaptIRG;
	bool m_etatCaptIRD;

	// ces variables sont mises � jour par l'ack
	bool m_bCaptIRArrPhone;
	bool m_bCaptIRGPhone;
	bool m_bCaptIRDPhone;


	static const int m_vitessePrecision;


	// ports capteurs, servo, led, 

	static volatile uint8_t &m_captArrPin;
	static volatile uint8_t &m_captGPin;
	static volatile uint8_t &m_captDPin;
	static volatile uint8_t &m_captArrDDR;
	static volatile uint8_t &m_captGDDR;
	static volatile uint8_t &m_captDDDR;
	static const uint8_t &m_captArrBit;
	static const uint8_t &m_captGBit;
	static const uint8_t &m_captDBit;

	static volatile uint8_t &m_ledLDDR;

	static volatile uint8_t &m_USPort;
	static volatile uint8_t &m_USDDR;
	static const uint8_t &m_USBit;

	static volatile uint8_t &m_servoPort;
	static volatile uint8_t &m_servoDDR;
	static const uint8_t &m_servoBit;
};


inline void Robot::putON(volatile uint8_t &port, const uint8_t &bit)
{
	port |= bit;
}

inline void Robot::putOFF(volatile uint8_t &port, const uint8_t &bit)
{
	port &= ~bit;
}


#endif
