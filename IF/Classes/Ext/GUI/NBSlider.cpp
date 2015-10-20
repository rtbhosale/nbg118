//
//  NBSlider.cpp
//  clipTest
//
//  Created by fusheng on 15-10-16.
//
//

#include "NBSlider.h"
#include "ui/UIHelper.h"
#include "CCTypesExt.h"

float NBSlider::getValue()
{
    return _value;
}
void NBSlider::setValue(float value)
{
    
    float x = value * _thumbMaxLength;
    
    _thumbRenderer->setPositionX(x);
    
    Size s = _barRenderer->getContentSize();
    
    s.width = value* _thumbMaxLength;
    
    _barRenderer->setContentSize(s);
    
    _value = value;
    
    if (_eventCallback)
    {
        _eventCallback(this,EventType::ON_PERCENTAGE_CHANGED);
    }
}


void NBSlider::setMinimumValue(float minValue)
{
    this->m_minValue = minValue;
}

void NBSlider::setMaximumValue(float maxValue)
{
    this->m_maxValue = maxValue;
}


NBSlider* NBSlider::create(const std::string& backGroundTextureName,
                           const std::string& barTextureName,
                           const std::string& thumbTextureName,
                           TextureResType resType
                           )
{
    NBSlider* widget = new (std::nothrow) NBSlider();
    if (widget && widget->init(backGroundTextureName,barTextureName,thumbTextureName,resType))
    {
        widget->autorelease();
        return widget;
    }
    CC_SAFE_DELETE(widget);
    return nullptr;
}





bool NBSlider::init(const std::string &backGroundTextureName, const std::string &barTextureName, const std::string &thumbTextureName,
                    TextureResType resType)
{
    if(!Node::init())
    {
        return false;
    }
    
    _textureResType = resType;
    
    if (_textureResType == TextureResType::LOCAL) {
        _barRenderer = Scale9Sprite::create(barTextureName);
        
        _progressBarRenderer = Scale9Sprite::create(backGroundTextureName);
        
        _thumbRenderer = Sprite::create(thumbTextureName);
    }
    else if (_textureResType == TextureResType::PLIST)
    {
        
        _barRenderer = Scale9Sprite::createWithSpriteFrameName(barTextureName);
        
        _progressBarRenderer = Scale9Sprite::createWithSpriteFrameName(backGroundTextureName);
        
        _thumbRenderer = Sprite::createWithSpriteFrameName(thumbTextureName);

    }
   
    
    this->addChild(_progressBarRenderer);
    this->addChild(_barRenderer);
    this->addChild(_thumbRenderer);
    
    
    _barRenderer->setAnchorPoint(Vec2(0,0.0));
    _progressBarRenderer->setAnchorPoint(Vec2(0,0.0));
    
    _thumbRenderer->setPositionY(_progressBarRenderer->getContentSize().height/2);
    
    _thumbRenderer->setAnchorPoint(Vec2(0.5,0.5));
    
    
    _thumbMaxLength = _barRenderer->getContentSize().width;
    
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    
    listener->onTouchBegan = CC_CALLBACK_2(NBSlider::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(NBSlider::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(NBSlider::onTouchEnded, this);
    listener->onTouchCancelled = CC_CALLBACK_2(NBSlider::onTouchCancelled, this);
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    
    return true;
    
}


void NBSlider::setCapInsets(const Rect &capInsets)
{
    setCapInsetsBarRenderer(capInsets);
    setCapInsetProgressBarRebderer(capInsets);
}

void NBSlider::setCapInsetsBarRenderer(const Rect &capInsets)
{
    _capInsetsBarRenderer = ui::Helper::restrictCapInsetRect(capInsets, _barRenderer->getContentSize());

    _barRenderer->setCapInsets(_capInsetsBarRenderer);
}

void NBSlider::setCapInsetProgressBarRebderer(const Rect &capInsets)
{
    _capInsetsProgressBarRenderer = ui::Helper::restrictCapInsetRect(capInsets, _progressBarRenderer->getContentSize());
    

    _progressBarRenderer->setCapInsets(_capInsetsProgressBarRenderer);
}

void NBSlider::addEventListener(const nbSliderCallBack& callback)
{
    _eventCallback = callback;
}
void NBSlider::setContentSize(const Size & var)
{
  
    
    _barRenderer->setContentSize(var);
    
    _progressBarRenderer->setContentSize(var);
    
    _thumbMaxLength = _progressBarRenderer->getContentSize().width;
    
    _thumbRenderer->setPositionY(_progressBarRenderer->getContentSize().height/2);
}

bool NBSlider::onTouchBegan(Touch *touch, Event *unusedEvent)
{
    if (isMoved) {
        return false;
    }
    if(isTouchInside(_thumbRenderer,touch))
    {
        isMoved = true;
        return true;
    }
    return false;
}

void NBSlider::onTouchMoved(Touch *touch, Event *unusedEvent)
{

    
    float tryX = _progressBarRenderer->convertToNodeSpace(touch->getLocation()).x;
    
    if (tryX<0) {
        tryX = 0;
    }
    if (tryX>_thumbMaxLength) {
        tryX = _thumbMaxLength;
    }
    
    float percent = tryX/_thumbMaxLength;
    
    setValue(percent);


    
}

void NBSlider::onTouchEnded(Touch *touch, Event *unusedEvent)
{
    isMoved = false;
}

void NBSlider::onTouchCancelled(Touch *touch, Event *unusedEvent)
{
    isMoved = false;
}