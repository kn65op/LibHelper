/* 
 * File:   Helper.h
 * Author: tomko
 *
 * Created on 18 listopad 2011, 16:50
 */

#ifndef HELPER_H
#define	HELPER_H

#include <string>

/**
 * Klasa udostępniająca statyczne funkcje pomocnicze.
 */
class Helper
{
public:
  /**
   * Funkcja zamieniająca integer na string.
   * @param n Integer, który chcemy zamienić.
   * @return String odpowiadający tej liczbie. Jeśli przekazana liczba nie jest całkowita to następuje obcięcie (np. z 5.6 tworzone jest "5").
   */
  static std::string intToString(int n);
  /**
   * Funkcja zmieniająca double na std::string
   * @param n double do zmiany.
   * @return std::string odpowiadający danej liczbie.
   */
  static std::string doubleToString(double n);
private:
  Helper();
  Helper(const Helper & h);
};

#endif	/* HELPER_H */

