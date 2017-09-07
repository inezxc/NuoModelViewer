//
//  NuoTextureMesh.h
//  ModelViewer
//
//  Created by middleware on 11/3/16.
//  Copyright © 2016 middleware. All rights reserved.
//

#import "NuoMesh.h"


@interface NuoTextureMesh : NuoMesh


@property (nonatomic, weak) id<MTLTexture> modelTexture;


- (instancetype)initWithDevice:(id<MTLDevice>)device;

/**
 *  the pixelFormat is used for the target color attachement and
 *  may or may not the same as to that of modelTexture. Metal supports
 *  this as implicit pixel format conversion.
 *
 *  sampleCount may be 1 if MSAA is not required, usually when there is no 3D involved and
 *  pixels between source and target are aligned
 */
- (void)makePipelineAndSampler:(MTLPixelFormat)pixelFormat withSampleCount:(NSUInteger)sampleCount;

@end
