/*
 * Реализуйте рассказанный на лекции класс Function, позволяющий создавать, вычислять и инвертировать функцию,
 * состоящую из следующих элементарных операций:
 * прибавить вещественное число x;
 * вычесть вещественное число x.
 * При этом необходимо объявить константными все методы, которые по сути такими являются.
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class FunctionPart{
public:
    FunctionPart(char op, double v){
        operation = op;
        value = v;
    }

    double Apply(double source_value) const {
        if(operation == '+'){
            return source_value + value;
        }else{
            return source_value - value;
        }
    }

    void Invert(){
        if(operation == '+'){
            operation = '-';
        }else{
            operation = '+';
        }
    }

private:
    char operation;
    double value;
};

class Function{
public:
    double Apply(double value) const{
        for(auto& part : parts){
            value = part.Apply(value);
        }
        return value;
    }
    void AddPart(char operation, double value){
        parts.push_back({operation, value});
    }
    void Invert(){
        for(auto& part : parts){
            part.Invert();
        }
        reverse(begin(parts), end(parts));
    }
private:
    vector<FunctionPart> parts;
};

struct Image {
   double quality;
   double freshness;
   double rating;
};

struct Params {
   double a;
   double b;
   double c;
};

Function MakeWeightFunction(const Params& params,
                           const Image& image) {
   Function function;
   function.AddPart('-', image.freshness * params.a + params.b);
   function.AddPart('+', image.rating * params.c);
   return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
   Function function = MakeWeightFunction(params, image);
   return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
                             const Image& image,
                             double weight) {
   Function function = MakeWeightFunction(params, image);
   function.Invert();
   return function.Apply(weight);
}

int main() {
   Image image = {10, 2, 6};
   Params params = {4, 2, 6};
   cout << ComputeImageWeight(params, image) << endl;
   cout << ComputeQualityByWeight(params, image, 46) << endl;
   return 0;
}