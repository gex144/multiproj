//
//  MPTitleLayer.cpp
//  HelloCpp
//
//  Created by Tyrice Clark on 3/31/13.
//  Copyright (c) 2013 Bullets in a Burning Box, Inc. All rights reserved.
//

#include "stdafx.h"
#include "MPTitleLayer.h"
#include "MPMapScene.h"
#include "MPBox2DScene.h"
#include "MPAudioScene.h"
#include "MPGuiTestScene.h"
#include "MPMacros.h"

USING_NS_CC;

bool MPTitleLayer::init(){
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    
    // Scene title
    CCLabelTTF* pLabel = CCLabelTTF::create("Title Scene", "Arial", TITLE_FONT_SIZE);
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));
    this->addChild(pLabel, 1);
    
	// Layout the selectable labels.
    
	int yInc = 40;
	int xPos = 250;
	int yPos = 100;
    
	// Box2D menu item label
    CCLabelTTF* box2DLabel = CCLabelTTF::create("Box 2D Scene", "Arial", TITLE_FONT_SIZE);
    box2DLabel->setPosition(CCPointZero);
    CCMenuItemLabel *box2DItem = CCMenuItemLabel::create(
                                                         box2DLabel,
                                                         this,
                                                         menu_selector(MPTitleLayer::selectBox2D));
	box2DItem->setPosition(xPos, yPos);
    
	// GUI Test menu item label
	yPos += yInc;
    CCLabelTTF* guiTestLabel = CCLabelTTF::create("GUI Test Scene", "Arial", TITLE_FONT_SIZE);
    guiTestLabel->setPosition(CCPointZero);
    CCMenuItemLabel *guiTestItem = CCMenuItemLabel::create(
                                                           guiTestLabel,
                                                           this,
                                                           menu_selector(MPTitleLayer::selectGuiTest));
	guiTestItem->setPosition(xPos, yPos);
    
    // Audio Button
	yPos += yInc;
    CCLabelTTF* audioLabel = CCLabelTTF::create("Audio Scene", "Arial", TITLE_FONT_SIZE);
    audioLabel->setPosition(CCPointZero);
    
    CCMenuItemLabel *audioItem = CCMenuItemLabel::create(
                                                         audioLabel,
                                                         this,
                                                         menu_selector(MPTitleLayer::selectAudio));
	audioItem->setPosition(xPos, yPos);
    
    // Map Button
	yPos += yInc;
    CCLabelTTF* mapLabel = CCLabelTTF::create("Map Scene", "Arial", TITLE_FONT_SIZE);
    mapLabel->setPosition(CCPointZero);
    
    CCMenuItemLabel *mapItem = CCMenuItemLabel::create(
                                                       mapLabel,
                                                       this,
                                                       menu_selector(MPTitleLayer::selectMap));
	mapItem->setPosition(xPos, yPos);
    
    
    
	// Close button
    CCMenuItemImage *closeItem = CCMenuItemImage::create(
                                                         "CloseNormal.png",
                                                         "CloseSelected.png",
                                                         this,
                                                         menu_selector(MPTitleLayer::menuCloseCallback));
	closeItem->setPosition(ccp(
                               origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                               origin.y + closeItem->getContentSize().height/2));
    
	// Menu container
    CCMenu * menu = CCMenu::create(box2DItem, guiTestItem, audioItem, mapItem, closeItem, NULL);
    menu->setPosition(CCPointZero);
    this->addChild(menu, 1);
    
    return true;
}

void MPTitleLayer::selectBox2D(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(MPBox2DScene::create());
}

void MPTitleLayer::selectGuiTest(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(MPGuiTestScene::create());
}

void MPTitleLayer::selectAudio(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(MPAudioScene::create());
}

void MPTitleLayer::selectMap(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(MPMapScene::create());
}

void MPTitleLayer::menuCloseCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC )
    exit(0);
#endif
}