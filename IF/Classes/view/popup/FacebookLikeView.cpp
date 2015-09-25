//
//  FacebookLikeView.cpp
//  IF
//
//  Created by xingxiaorui on 14-11-10.
//
//

#include "FacebookLikeView.h"
#include "SetAccountView.h"
#include "PopupViewController.h"
#include "SceneController.h"
#include "LocalController.h"
#include "CCCommonUtils.h"
#include "LoginServiceView.h"
#include "NetController.h"
#include "FBUtilies.h"
#include "../../Ext/CCDevice.h"
#include "UserBindCommand.h"
#include "SuggestionView.h"
#include "PopupViewController.h"
#include "SettingPopUpView.h"
#include "RegisterView.h"
#include "ParticleController.h"
#include "YesNoDialog.h"
#include "WorldController.h"
#include "QuestRewardCommand.h"


FacebookLikeView* FacebookLikeView::create() {
    auto ret = new FacebookLikeView();
    if (ret && ret->init()){
        ret->autorelease();
    } else {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

bool FacebookLikeView::init() {
    bool ret = false;
    if (PopupBaseView::init()) {
        CCBLoadFile("FacebookLikeView",this,this);
        CCSize size=CCDirector::sharedDirector()->getWinSize();
        setContentSize(size);
        
        m_titleLabel->setString(_lang("2000215"));
        m_infoLabel->setString(_lang("2000216"));
        CCCommonUtils::setButtonTitle(m_goBtn, _lang("2000214").c_str());
        ret = true;
    }
    return ret;
}

void FacebookLikeView::onEnter() {
    PopupBaseView::onEnter();
    setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
    setTouchEnabled(true);
    //CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, Touch_Default, false);
}

void FacebookLikeView::onExit() {
    setTouchEnabled(false);
    PopupBaseView::onExit();
}

void FacebookLikeView::onGoClick(CCObject * pSender, Control::EventType pCCControlEvent)
{
    PopupViewController::getInstance()->removePopupView(this);
    FSTaskCommand * cmd = new FSTaskCommand(2);
    cmd->sendAndRelease();
    GameController::getInstance()->gotoFaceBookLike();
    
}

SEL_CCControlHandler FacebookLikeView::onResolveCCBCCControlSelector(cocos2d::CCObject *pTarget, const char *pSelectorName) {
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onGoClick", FacebookLikeView::onGoClick);
    return NULL;
}

bool FacebookLikeView::onAssignCCBMemberVariable(cocos2d::CCObject *pTarget, const char *pMemberVariableName, cocos2d::CCNode *pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this, "m_titleLabel", CCLabelIF*, m_titleLabel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this, "m_infoLabel", CCLabelIF*, m_infoLabel);
    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this, "m_goBtn", CCControlButton*, m_goBtn);
    CCB_MEMBERVARIABLEASSIGNER_GLUE_WEAK(this, "m_touchNode", CCNode*, m_touchNode);
    return false;
}

bool FacebookLikeView::onTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    return true;
}

void FacebookLikeView::onTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    if (isTouchInside(m_touchNode, pTouch)) {
        return;
    }
    PopupViewController::getInstance()->removePopupView(this);
}
