#pragma once
#ifndef DISCIPLINE_TYPE_H
#define DISCIPLINE_TYPE_H

//Built-in Imports
#include <Arduino.h>

//Common imports

//Custom imports

namespace Discipline {
  enum class Type {
    Foil,
    Sabre,
    Epee
  };
}
#endif