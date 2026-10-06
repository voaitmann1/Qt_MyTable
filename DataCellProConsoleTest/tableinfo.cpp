#include "tableinfo.h"

bool TypeNIsCorrectArrayTypeN(int TypeN){
    return(TypeN==DoubleArrayTypeN || TypeN==FloatArrayTypeN || TypeN==IntArrayTypeN || TypeN==BoolArrayTypeN ||  TypeN==StringArrayTypeN);
}
bool TypeNIsCorrectNumberTypeN(int TypeN){
    return(TypeN==DoubleTypeN || TypeN==FloatTypeN || TypeN==IntTypeN);
}
bool TypeNIsDBFieldHeaderForChoiceTypeN(int TypeN){
    return(TypeN==DoubleItemsDBFieldHeaderCellTypeN || TypeN==IntItemsDBFieldHeaderCellTypeN || TypeN==StringItemsDBFieldHeaderCellTypeN);
}
bool TypeNIsCorrect(int TypeN){
    return
        (
            TypeNIsCorrectNumberTypeN(TypeN) ||
            TypeNIsCorrectNumberTypeN(TypeN) ||
            TypeNIsDBFieldHeaderForChoiceTypeN(TypeN) ||
            TypeN==BoolTypeN || TypeN==StringTypeN
        );
}



