/**
   \file guss1d.hpp
   \brief gauss model
   \author Junhua Gu
 */


#ifndef GAUSS_MODEL_H_
#define GAUSS_MODEL_H_
#define OPT_HEADER
#include <core/fitter.hpp>
#include <cmath>

namespace opt_utilities
{
  template <typename T>
  class gauss1d
    :public model<T,T,std::vector<T>,std::string>
  {
  private:
    model<T,T,std::vector<T> >* do_clone()const
    {
      return new gauss1d<T>(*this);
    }

    const char* do_get_type_name()const
    {
      return "1d gaussian";
    }
  public:
    gauss1d()
    {
      this->push_param_info(param_info<std::vector<T> >("N",1));
      this->push_param_info(param_info<std::vector<T> >("x0",0));
      this->push_param_info(param_info<std::vector<T> >("sigma",1));
    }

  public:
    T do_eval(const T& x,const std::vector<T>& param)
    {
      T N=get_element(param,0);
      T x0=get_element(param,1);
      T sigma=get_element(param,2);
      T y=(x-x0)/sigma;
      return N*exp(-y*y/2);
    }

  private:
    std::string do_get_information()const
    {
      return "<math xmlns=\"http://www.w3.org/1998/Math/MathML\" display=\"block\" class=\"equation\"><mi>f</mi><mrow><mo class=\"MathClass-open\">(</mo><mrow><mi>x</mi><mo class=\"MathClass-punc\">;</mo><mi>N</mi><mo class=\"MathClass-punc\">,</mo><msub><mrow><mi>x</mi></mrow><mrow><mn>0</mn></mrow></msub><mo class=\"MathClass-punc\">,</mo><mi>σ</mi></mrow><mo class=\"MathClass-close\">)</mo></mrow> <mo class=\"MathClass-rel\">=</mo> <mi>N</mi><msup><mrow><mi>e</mi></mrow><mrow><mo class=\"MathClass-bin\">−</mo><mfrac><mrow><msup><mrow><mrow><mo class=\"MathClass-open\">(</mo><mrow><mi>x</mi><mo class=\"MathClass-bin\">−</mo><msub><mrow><mi>x</mi></mrow><mrow><mn>0</mn></mrow></msub></mrow><mo class=\"MathClass-close\">)</mo></mrow></mrow><mrow><mn>2</mn></mrow></msup></mrow><mrow><mn>2</mn><msup><mrow><mi>σ</mi></mrow><mrow><mn>2</mn></mrow></msup></mrow></mfrac>    </mrow></msup></math>";
    }
  };
}



#endif
//EOF
