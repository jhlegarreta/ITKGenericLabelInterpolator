/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#ifndef itkLabelSelectionImageAdaptor_h
#define itkLabelSelectionImageAdaptor_h

#include "itkLabelSelectionPixelAccessor.h"

namespace itk
{
/** \class LabelSelectionImageAdaptor
 * \brief Presents a label image as a binary image of one label
 *
 * Additional casting is performed according to the input and output image
 * types following C++ default casting rules.
 *
 * \ingroup ImageAdaptors
 * \ingroup ITKImageAdaptors
 * \ingroup GenericLabelInterpolator
 */
template< class TImage, class TOutputPixelType >
class ITK_EXPORT LabelSelectionImageAdaptor:public
  ImageAdaptor< TImage,
                Accessor::LabelSelectionPixelAccessor<
                  typename TImage::PixelType,
                  TOutputPixelType >   >
{
public:
  /** Standard class typedefs. */
  typedef LabelSelectionImageAdaptor Self;
  typedef ImageAdaptor< TImage, Accessor::LabelSelectionPixelAccessor<
                          typename TImage::PixelType,
                          TOutputPixelType > >  Superclass;

  typedef SmartPointer< Self >       Pointer;
  typedef SmartPointer< const Self > ConstPointer;

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  /** Run-time type information (and related methods). */
  itkTypeMacro(LabelSelectionImageAdaptor, ImageAdaptor);

  void SetAcceptedValue(typename TImage::PixelType value) {
    this->GetPixelAccessor().SetAcceptedValue(value);
  }

protected:
  LabelSelectionImageAdaptor() {}
  ~LabelSelectionImageAdaptor() ITK_OVERRIDE {}

private:
  LabelSelectionImageAdaptor(const Self &); //purposely not implemented
  void operator=(const Self &);  //purposely not implemented
};
} // end namespace itk

#endif
