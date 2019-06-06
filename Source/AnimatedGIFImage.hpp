//
//  AnimatedGIFImage.hpp
//  AnimatedGif
//
//  Created by Sander ter Braak on 04/06/2019.
//
//

#ifndef AnimatedGIFImage_hpp
#define AnimatedGIFImage_hpp

#include "../JuceLibraryCode/JuceHeader.h"


class AnimatedGIFImage : public Array<Image>
{
    
public:
    
    static AnimatedGIFImage getFromFile (const File& file);
    static AnimatedGIFImage getFromStream (InputStream& stream);
    
    void setFrameDuration(int frame, int ms);
    int getFrameDuration(int frame);
    
    bool isAnimated();
    int getNumFrames();
    
private:
    
    Array<int> frameTimes;
};

class AnimatedGIFImageFormat  : public ImageFileFormat
{
public:
    //==============================================================================
    AnimatedGIFImageFormat();
    ~AnimatedGIFImageFormat();
    
    //==============================================================================
    String getFormatName() override;
    bool usesFileExtension (const File&) override;
    bool canUnderstand (InputStream&) override;
    Image decodeImage (InputStream&) override;
    
    AnimatedGIFImage decodeAnimation (InputStream&);
    
    bool writeImageToStream (const Image&, OutputStream&) override;
};




#endif /* AnimatedGIFImage_hpp */
