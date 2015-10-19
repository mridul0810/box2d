  /*
* Copyright (c) 2013 Google, Inc.
*
* This software is provided 'as-is', without any express or implied
* warranty.  In no event will the authors be held liable for any damages
* arising from the use of this software.
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
* 1. The origin of this software must not be misrepresented; you must not
* claim that you wrote the original software. If you use this software
* in a product, an acknowledgment in the product documentation would be
* appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
* misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
*/
#ifndef DAM_BREAK_H
#define DAM_BREAK_H

//! The Dominos class which makes all the elements in simulation
/**
  * It inherits Test class and has all the code to make all the elements
  * It has two member functions GetDefaultViewZoom(), Create() and a constructor
  */

class Dominos : public Test
{
public:
      /** Constructor for Dominos class
       * A normal member taking no arguments and returning an float32 value representing the zoom.
       * @return The default zoom required, Here taken as 1.25f
       */
	Dominos()
	{
		/**
     *Particles have radius set to 0.05f and damping to 0.1f
     *
     */ 

     m_particleSystem->SetRadius(0.05f);
     m_particleSystem->SetDamping(0.1f);


     //Making all the particle groups
     {
       b2PolygonShape shape;// Initializing a shape to use for the particles
       shape.SetAsBox(0.8f, 1.0f, b2Vec2(-1.2f, 1.01f), 0);// 
       b2ParticleGroupDef pd;
       b2ParticleGroupDef pd1;
       pd.flags = TestMain::GetParticleParameterValue();
       pd.flags=b2_viscousParticle;
       pd.shape = &shape;
       pd.position.Set(43, 25);

       pd1.flags = TestMain::GetParticleParameterValue();
       pd1.flags=b2_viscousParticle;
       pd1.shape = &shape;
       pd1.position.Set(43, 25);

       b2ParticleGroup * group[20];
       for(int i=0;i<20;i++){
        pd.position.Set(43, 25+i*2);
        if(i<10){group[i] = m_particleSystem->CreateParticleGroup(pd);}
        else{group[i] = m_particleSystem->CreateParticleGroup(pd1);}
			
        if (pd.flags & b2_colorMixingParticle)
        {
          ColorParticleGroup(group[i], 0);

				//ColorParticleGroup(group,0);
        }}

      }

      b2Body* b1;  
      {

        b2EdgeShape shape; 
        shape.Set(b2Vec2(-90.0f, 0.0f), b2Vec2(-19.0f, 0.0f));
        b2BodyDef bd; 
        b1 = m_world->CreateBody(&bd); 
        b1->CreateFixture(&shape, 0.0f);
      }
      {
      //Right wall of tank
        b2Body* a1;  
        {

          b2EdgeShape shape; 
          shape.Set(b2Vec2(0.0f, -90.0f), b2Vec2(0.0f, 90.0f));
          b2BodyDef bd; 
          bd.position.Set(45.0f,0.0f);
          a1 = m_world->CreateBody(&bd); 
          a1->CreateFixture(&shape, 0.0f);
        }
    //left wall of tank
        {
          b2PolygonShape shape;
          shape.SetAsBox(0.25f, 20.0f);

          b2BodyDef bd;
          bd.position.Set(35.0f, 40.0f);
          b2Body* ground = m_world->CreateBody(&bd);
          ground->CreateFixture(&shape, 0.0f);
        }
    //pipe structure of tank
        {
          b2PolygonShape shape;
          shape.SetAsBox(8.0f, 0.25f);

          b2BodyDef bd;
          bd.position.Set(35.25f, 20.0f);
          b2Body* ground = m_world->CreateBody(&bd);
          ground->CreateFixture(&shape, 0.0f);
        }
        {
          b2PolygonShape shape;
          shape.SetAsBox(1.0f, 0.25f);

          b2BodyDef bd;
          bd.position.Set(25.75f, 20.0f);
          b2Body* ground = m_world->CreateBody(&bd);
          ground->CreateFixture(&shape, 0.0f);
          bd.position.Set(25.0f, 14.0f);
          shape.SetAsBox(0.2,3, b2Vec2(-2.0f,2.f), 225);
          b2Body* slant = m_world->CreateBody(&bd);
          slant->CreateFixture(&shape, 0.0f);
        }
        {
          b2PolygonShape shape;
          shape.SetAsBox(5.0f, 0.25f);

          b2BodyDef bd;
          bd.position.Set(40.0f, 45.0f);
          b2Body* ground = m_world->CreateBody(&bd);
          ground->CreateFixture(&shape, 0.0f);


        }

      }

    //Top horizontal shelf
      {
        b2PolygonShape shape;
        shape.SetAsBox(10.0f, 0.25f);

        b2BodyDef bd;
        bd.position.Set(35.0f, 17.0f);
        b2Body* ground = m_world->CreateBody(&bd);
        ground->CreateFixture(&shape, 0.0f);


      }

    //Dominos


    //The tank pulley system closing door
      {

        b2BodyDef *bd = new b2BodyDef;
        b2BodyDef *myBodyDef = new b2BodyDef;
        bd->type = b2_dynamicBody;
        bd->position.Set(32.0f,25);
        bd->fixedRotation = true;
      myBodyDef->type = b2_staticBody; //this will be a static body
      myBodyDef->fixedRotation = true;
      
      //The open box
      b2FixtureDef *fd1 = new b2FixtureDef;
      fd1->density = 10.0;
      fd1->friction = 0.5;
      fd1->restitution = 0.f;
      fd1->shape = new b2PolygonShape;
      b2PolygonShape bs1;
      bs1.SetAsBox(2,0.2, b2Vec2(0.f,-1.9f), 0);
      fd1->shape = &bs1;
      b2FixtureDef *fd2 = new b2FixtureDef;
      fd2->density = 10.0;
      fd2->friction = 0.5;
      fd2->restitution = 0.f;
      fd2->shape = new b2PolygonShape;
      b2PolygonShape bs2;
      bs2.SetAsBox(0.2,2, b2Vec2(2.0f,0.f), 0);
      fd2->shape = &bs2;
      b2FixtureDef *fd3 = new b2FixtureDef;
      fd3->density = 10.0;
      fd3->friction = 0.5;
      fd3->restitution = 0.f;
      fd3->shape = new b2PolygonShape;
      b2PolygonShape bs3;
      bs3.SetAsBox(0.2,2, b2Vec2(-2.0f,0.f), 0);
      fd3->shape = &bs3;

      b2Body* box1 = m_world->CreateBody(bd);
      box1->CreateFixture(fd1);
      box1->CreateFixture(fd2);
      box1->CreateFixture(fd3);



      bd->position.Set(27,29);
      b2Body* box3 = m_world->CreateBody(bd);
      box3->CreateFixture(fd1);
      box3->CreateFixture(fd2);
      box3->CreateFixture(fd3);

      //The bar
      bd->position.Set(25,25);

      fd2->density = 34.0;    
      b2Body* box2 = m_world->CreateBody(bd);
      box2->CreateFixture(fd2);
      b2RevoluteJointDef weldJointDef;
      b2Vec2 anchor;
      anchor.Set(27,25);
      weldJointDef.Initialize(box2, box3, anchor);
      m_world->CreateJoint(&weldJointDef);

      myBodyDef->position.Set(18.5f,11.0f);
      b2Body* box4 = m_world->CreateBody(myBodyDef);
      bs1.SetAsBox(3,0.2, b2Vec2(0.f,-3.5f), 0);
      bs2.SetAsBox(0.2,4, b2Vec2(3.0f,0.0f), 0);
      bs3.SetAsBox(0.2,3, b2Vec2(-3.0f,-1.0f), 0);
      box4->CreateFixture(fd1);
      box4->CreateFixture(fd2);
      box4->CreateFixture(fd3);
      myBodyDef->position.Set(-5,12);
      b2Body* box5 = m_world->CreateBody(myBodyDef);
      bs1.SetAsBox(3,0.2, b2Vec2(0.f,-1.9f), 0);
      bs3.SetAsBox(0.2,2, b2Vec2(-3.0f,0.0f), 0);
      box5->CreateFixture(fd1);
      box5->CreateFixture(fd3);
      

      // The pulley joint
      b2PulleyJointDef* myjoint = new b2PulleyJointDef();
      b2Vec2 worldAnchorOnBody2(32.0f, 25); // Anchor point on body 1 in world axis
      b2Vec2 worldAnchorOnBody1(27, 25); // Anchor point on body 2 in world axis
      b2Vec2 worldAnchorGround2(27, 40); // Anchor point for ground 1 in world axis
      b2Vec2 worldAnchorGround1(32.0f, 40); // Anchor point for ground 2 in world axis
      float32 ratio = 1.0f; // Define ratio
      myjoint->Initialize(box1, box2, worldAnchorGround1, worldAnchorGround2, box1->GetWorldCenter(), box2->GetWorldCenter(), ratio);
      m_world->CreateJoint(myjoint);

    }
    {
      b2Body* spherebody;

      b2CircleShape circle;
      circle.m_radius = 0.5;

      b2FixtureDef ballfd;
      ballfd.shape = &circle;
      ballfd.density = 10.0f;
      ballfd.friction = 0.0f;
      ballfd.restitution = 0.5f;

    
      ballfd.restitution=0.0;
      ballfd.density=15.0f;
      for (int i = 0; i < 5; ++i)
      {
        b2BodyDef ballbd;
        ballbd.type = b2_dynamicBody;
        ballbd.position.Set(32.0+(i-4)*1.0/4, 30.0+i);
        spherebody = m_world->CreateBody(&ballbd);
        spherebody->CreateFixture(&ballfd);
      }
      ballfd.density = 25.0f;
      b2BodyDef ballbd;
      ballbd.type = b2_dynamicBody;
      ballbd.position.Set(15.5f,25);
      spherebody = m_world->CreateBody(&ballbd);
      spherebody->CreateFixture(&ballfd);
      {
       ballfd.density = 25.0f;
       b2BodyDef ballbd;
       ballbd.type = b2_dynamicBody;
       ballbd.position.Set(-3,15);
       spherebody = m_world->CreateBody(&ballbd);
       spherebody->CreateFixture(&ballfd);
     }
   }

   {
    {
      b2BodyDef *bd = new b2BodyDef;
      bd->type = b2_dynamicBody;
      bd->position.Set(13,10);
      bd->fixedRotation = true;

      //The open box
      b2FixtureDef *fd1 = new b2FixtureDef;
      fd1->density = 10.0;
      fd1->friction = 0.5;
      fd1->restitution = 0.f;
      fd1->shape = new b2PolygonShape;
      b2PolygonShape bs1;
      bs1.SetAsBox(2,0.2, b2Vec2(0.f,-1.9f), 0);
      fd1->shape = &bs1;
      b2FixtureDef *fd2 = new b2FixtureDef;
      fd2->density = 10.0;
      fd2->friction = 0.5;
      fd2->restitution = 0.f;
      fd2->shape = new b2PolygonShape;
      b2PolygonShape bs2;
      bs2.SetAsBox(0.2,2, b2Vec2(2.0f,0.f), 0);
      fd2->shape = &bs2;
      b2FixtureDef *fd3 = new b2FixtureDef;
      fd3->density = 10.0;
      fd3->friction = 0.5;
      fd3->restitution = 0.f;
      fd3->shape = new b2PolygonShape;
      b2PolygonShape bs3;
      bs3.SetAsBox(0.2,2, b2Vec2(-2.0f,0.f), 0);
      fd3->shape = &bs3;

      b2Body* box1 = m_world->CreateBody(bd);
      box1->CreateFixture(fd1);
      box1->CreateFixture(fd2);
      box1->CreateFixture(fd3);

      //The bar
      bd->position.Set(3,16); 
      fd1->density = 30.0;
      //bs1.SetAsBox(1,0.2, b2Vec2(0.f,-1.9f), 0);   
      b2Body* box2 = m_world->CreateBody(bd);
      box2->CreateFixture(fd1);

      // The pulley joint
      b2PulleyJointDef* myjoint = new b2PulleyJointDef();
      b2Vec2 worldAnchorOnBody1(13, 10); // Anchor point on body 1 in world axis
      b2Vec2 worldAnchorOnBody2(3, 10); // Anchor point on body 2 in world axis
      b2Vec2 worldAnchorGround1(13, 20); // Anchor point for ground 1 in world axis
      b2Vec2 worldAnchorGround2(3, 20); // Anchor point for ground 2 in world axis
      float32 ratio = 1.0f; // Define ratio
      myjoint->Initialize(box1, box2, worldAnchorGround1, worldAnchorGround2, box1->GetWorldCenter(), box2->GetWorldCenter(), ratio);
      m_world->CreateJoint(myjoint);
    }
  }

  //The pendulum that knocks the dominos off
  {
    b2Body* b2;
    {
      b2PolygonShape shape;
      shape.SetAsBox(0.01f, 0.01f);

      b2BodyDef bd;
      bd.position.Set(-43.5f, 12.5f);
      b2 = m_world->CreateBody(&bd);
      b2->CreateFixture(&shape, 10.0f);
    }

    b2Body* b4;
    {
      b2PolygonShape shape;
      shape.SetAsBox(0.25f, 0.25f);

      b2BodyDef bd;
      bd.type = b2_dynamicBody;
      bd.position.Set(-43.5f, 8.0f);
      b4 = m_world->CreateBody(&bd);
      b4->CreateFixture(&shape, 2.0f);
    }

    b2RevoluteJointDef jd;
    b2Vec2 anchor;
    anchor.Set(-43.5f, 12.5f);
    jd.Initialize(b2, b4, anchor);
    m_world->CreateJoint(&jd);
  }


  //plank with a dominos
  {
    b2PolygonShape shape;
    shape.SetAsBox(5.0f, 0.25f);

    b2BodyDef bd;
    bd.position.Set(-6.0f, 7.0f);
    b2Body* ground = m_world->CreateBody(&bd);
    ground->CreateFixture(&shape, 0.0f);
  }

    //Dominos
  {
    b2PolygonShape shape;
    shape.SetAsBox(0.1f, 1.0f);

    b2FixtureDef fd;
    fd.shape = &shape;
    fd.density = 20.0f;
    fd.friction = 0.1f;
    
    for (int i = 1; i < 10; ++i)
    {
      b2BodyDef bd;
      bd.type = b2_dynamicBody;
      bd.position.Set(-10.5f + 1.0f * i, 8.3f);
      b2Body* body = m_world->CreateBody(&bd);
      body->CreateFixture(&fd);

    }
  //sphere with dominos
    b2Body* spherebody;

    b2CircleShape circle;
    circle.m_radius = 1.0f;

    b2FixtureDef ballfd;
    ballfd.shape = &circle;
    ballfd.density = 10.0f;
    ballfd.friction = 0.0f;
    ballfd.restitution = 0.5f;

    

    b2BodyDef ballbd;
    ballbd.type = b2_dynamicBody;
    ballbd.position.Set(-11.0f, 7.5f);
    spherebody = m_world->CreateBody(&ballbd);
    spherebody->CreateFixture(&ballfd);

//


  }
    //2,nd dominos
  {
    b2PolygonShape shape;
    shape.SetAsBox(7.0f, 0.25f);

    b2BodyDef bd;
    bd.position.Set(-38.0f, 7.0f);
    b2Body* ground = m_world->CreateBody(&bd);
    ground->CreateFixture(&shape, 0.0f);
  }

    //Dominos
  {
    b2PolygonShape shape;
    shape.SetAsBox(0.1f, 1.0f);

    b2FixtureDef fd;
    fd.shape = &shape;
    fd.density = 20.0f;
    fd.friction = 0.1f;
    
    for (int i = 0; i < 10; ++i)
    {
      b2BodyDef bd;
      bd.type = b2_dynamicBody;
      bd.position.Set(-42.5f + 1.0f * i, 8.3f);
      b2Body* body = m_world->CreateBody(&bd);
      body->CreateFixture(&fd);

    }
 


  }
  //  3,rd dominos
  {
    b2PolygonShape shape;
    shape.SetAsBox(5.0f, 0.25f);

    b2BodyDef bd;
    bd.position.Set(-38.0f, 16.0f);
    b2Body* ground = m_world->CreateBody(&bd);
    ground->CreateFixture(&shape, 0.0f);
  }

    //Dominos
  {
    b2PolygonShape shape;
    shape.SetAsBox(0.1f, 1.0f);

    b2FixtureDef fd;
    fd.shape = &shape;
    fd.density = 1.0f;
    fd.friction = 0.1f;
    
    for (int i = 0; i < 9; ++i)
    {
      b2BodyDef bd;
      bd.type = b2_dynamicBody;
      bd.position.Set(-43.0f + 1.0f * i, 17.3f);
      b2Body* body = m_world->CreateBody(&bd);
      body->CreateFixture(&fd);

    }
  //sphere with dominos
    b2Body* spherebody;

    b2CircleShape circle;
    circle.m_radius = 1.0f;

    b2FixtureDef ballfd;
    ballfd.shape = &circle;
    ballfd.density = 100.0f;
    ballfd.friction = 0.0f;
    ballfd.restitution = 0.5f;

    

    b2BodyDef ballbd;
    ballbd.type = b2_dynamicBody;
    ballbd.position.Set(-33.0f, 16.5f);
    spherebody = m_world->CreateBody(&ballbd);
    spherebody->CreateFixture(&ballfd);

    //Box connected to sphere

    b2PolygonShape shapex;
    shapex.SetAsBox(1,1);
    b2FixtureDef xd;
    xd.shape = &shapex;
    xd.friction = 0.0f;
    xd.density = 50.0f;
    b2BodyDef boxdefx;
    boxdefx.type = b2_dynamicBody;
    boxdefx.position.Set(-25.0f, 26.0f);
    b2Body* boxx = m_world->CreateBody(&boxdefx);
    boxx->CreateFixture(&xd); 
    {
    // The pulley joint
      b2PulleyJointDef* myjoint = new b2PulleyJointDef();
       b2Vec2 worldAnchorOnBody1(-33.5f, 17.0f); // Anchor point on body 1 in world axis
       b2Vec2 worldAnchorOnBody2(-25.0f, 26.0f); // Anchor point on body 2 in world axis
       b2Vec2 worldAnchorGround1(-33.0f, 26.0f); // Anchor point for ground 1 in world axis
       b2Vec2 worldAnchorGround2(-33.0f, 26.0f); // Anchor point for ground 2 in world axis
       float32 ratio = 1.0f; // Define ratio
       myjoint->Initialize(spherebody,boxx, worldAnchorGround1, worldAnchorGround2, spherebody->GetWorldCenter(), boxx->GetWorldCenter(), ratio);
       

       m_world->CreateJoint(myjoint);
     }



//


   }

   
    //1 'sthinged plank which is balanced by twoballs
    {
      {
      //The Plank which revolves.
        b2PolygonShape shape;                                                                 
        shape.SetAsBox(2.4f, 0.2f);                            
        b2BodyDef bd;
        bd.position.Set(-1.0f, 16.0f);                     
        bd.type = b2_dynamicBody;                           
        b2Body* body = m_world->CreateBody(&bd);           
        b2FixtureDef *fd = new b2FixtureDef;                
        fd->density = 1.f;                                  
        fd->shape = new b2PolygonShape;
        fd->shape = &shape;
        body->CreateFixture(fd);                            

      // Creating a hinge to rotate the platform
        b2PolygonShape shape2;                              
        shape2.SetAsBox(0.2f, 1.0f);                         
        b2BodyDef bd2;
        bd2.position.Set(-1.0, 16.0f);
        b2Body* body2 = m_world->CreateBody(&bd2);           
        
      // Revolute joint between the plank and the hinge.    
        b2RevoluteJointDef jointDef;                         
        jointDef.bodyA = body;                               
        jointDef.bodyB = body2;   
        jointDef.localAnchorA.Set(0,0);                     
        jointDef.localAnchorB.Set(0,0);
        jointDef.collideConnected = false;                  
        m_world->CreateJoint(&jointDef);                   
      }

//ball on rotating platform
      b2Body* spherebody;

      b2CircleShape circle;
      circle.m_radius = 0.5;

      b2FixtureDef ballfd;
      ballfd.shape = &circle;
      ballfd.density = 10.0f;
      ballfd.friction = 0.0f;
      ballfd.restitution = 0.6f;



      b2BodyDef ballbd;
      ballbd.type = b2_dynamicBody;
      ballbd.position.Set(-2.1f, 17.0f);
      spherebody = m_world->CreateBody(&ballbd);
      spherebody->CreateFixture(&ballfd);
      b2BodyDef ballbd1;
      ballbd1.type = b2_dynamicBody;
      ballbd1.position.Set(0.1f, 17.0f);
      spherebody = m_world->CreateBody(&ballbd1);
      spherebody->CreateFixture(&ballfd);

    }
    {
      {
      //The Plank which revolves.
        b2PolygonShape shape;                                                                 
        shape.SetAsBox(2.4f, 0.2f);                            
        b2BodyDef bd;
        bd.position.Set(-28.5f, 16.0f);                     
        bd.type = b2_dynamicBody;                           
        b2Body* body = m_world->CreateBody(&bd);           
        b2FixtureDef *fd = new b2FixtureDef;                
        fd->density = 1.f;                                  
        fd->shape = new b2PolygonShape;
        fd->shape = &shape;
        body->CreateFixture(fd);                            

      // Creating a hinge to rotate the platform
        b2PolygonShape shape2;                              
        shape2.SetAsBox(0.2f, 1.0f);                         
        b2BodyDef bd2;
        bd2.position.Set(-28.5f, 12.0f);
        b2Body* body2 = m_world->CreateBody(&bd2);           
        
      // Revolute joint between the plank and the hinge.    
        b2RevoluteJointDef jointDef;                         
        jointDef.bodyA = body;                               
        jointDef.bodyB = body2;   
        jointDef.localAnchorA.Set(0,0);                     
        jointDef.localAnchorB.Set(0,0);
        jointDef.collideConnected = false;                  
        m_world->CreateJoint(&jointDef);                   
      }

//ball on rotating platform
      b2Body* spherebody;

      b2CircleShape circle;
      circle.m_radius = 0.5;

      b2FixtureDef ballfd;
      ballfd.shape = &circle;
      ballfd.density = 1.0f;
      ballfd.friction = 0.0f;
      ballfd.restitution = 0.5f;



      b2BodyDef ballbd;
      ballbd.type = b2_dynamicBody;
      ballbd.position.Set(-28.5f, 17.0f);
      spherebody = m_world->CreateBody(&ballbd);
      spherebody->CreateFixture(&ballfd);
   
  }

   //The see-saw system at the bottom
  {
     //The triangle wedge
    b2Body* sbody;
    b2PolygonShape poly;
    b2Vec2 vertices[3];
    vertices[0].Set(-1,0);
    vertices[1].Set(1,0);
    vertices[2].Set(0,1.5);
    poly.Set(vertices, 3);
    b2FixtureDef wedgefd;
    wedgefd.shape = &poly;
    wedgefd.density = 10.0f;
    wedgefd.friction = 0.0f;
    wedgefd.restitution = 0.0f;
    b2BodyDef wedgebd;
    wedgebd.position.Set(-21.5f, 0.0f);
    sbody = m_world->CreateBody(&wedgebd);
    sbody->CreateFixture(&wedgefd);

       //The plank on top of the wedge
    b2PolygonShape shape;
    shape.SetAsBox(9.0f, 0.2f);
    b2BodyDef bd2;
    bd2.position.Set(-21.5f, 1.5f);
    bd2.type = b2_dynamicBody;
    b2Body* body = m_world->CreateBody(&bd2);
    b2FixtureDef *fd2 = new b2FixtureDef;
    fd2->density = 1.f;
    fd2->shape = new b2PolygonShape;
    fd2->shape = &shape;
    body->CreateFixture(fd2);

    b2RevoluteJointDef jd;
    b2Vec2 anchor;
    anchor.Set(-21.4f, 1.5f);
    jd.Initialize(sbody, body, anchor);
    m_world->CreateJoint(&jd);

       //The light box on the right side of the see-saw
    b2PolygonShape shape2;
    shape2.SetAsBox(1.0f, 1.0f);
    b2BodyDef bd3;
    bd3.position.Set(-28.5f, 2.0f);
    bd3.type = b2_dynamicBody;
    b2Body* body3 = m_world->CreateBody(&bd3);
    b2FixtureDef *fd3 = new b2FixtureDef;
    fd3->density = 0.01f;
    fd3->shape = new b2PolygonShape;
    fd3->shape = &shape2;
    body3->CreateFixture(fd3);
  }
  


 // Mridul's part
// Balloon part
  {
    b2Body* balloon[5];
    b2CircleShape circle;
    circle.m_radius = 1.0;  

    b2FixtureDef ballfd;
    ballfd.shape = &circle;
    ballfd.density = -10.0f;
    ballfd.friction = 0.0f;
    ballfd.restitution = 0.0f;

    b2BodyDef ballbd;
    ballbd.type = b2_dynamicBody;
    ballbd.position.Set(15.0f, 42.0f);


    for (int i=0;i<5;i++)
      { balloon[i] = m_world->CreateBody(&ballbd);
        balloon[i]->CreateFixture(&ballfd);
        balloon[i]->SetGravityScale(-1);
      }

      b2BodyDef myBodyDef;
    myBodyDef.type = b2_dynamicBody; //this will be a dynamic body
    myBodyDef.position.Set(15.0f, 37.0f); //set the starting position
    myBodyDef.angle = 0;
    b2Body* dynamicBody = m_world->CreateBody(&myBodyDef);
    b2PolygonShape boxShape;
    boxShape.SetAsBox(1,1);

    b2FixtureDef boxFixtureDef;
    boxFixtureDef.shape = &boxShape;
    boxFixtureDef.density = 1;
    dynamicBody->CreateFixture(&boxFixtureDef);
    b2DistanceJointDef jointDef[5];
    for (int i=0;i<5;i++)
    { 
      jointDef[i].bodyA = balloon[i];
      jointDef[i].bodyB = dynamicBody;
      jointDef[i].collideConnected = true;
      jointDef[i].length = 10;
      m_world->CreateJoint( &jointDef[i] );
    }
    
  }

//Balloon part end

  //part 1


  {
    b2PolygonShape shape;
    shape.SetAsBox(5.0f, 0.25f);

    b2BodyDef bd;
    bd.position.Set(-25.0f, 25.0f);
    b2Body* ground = m_world->CreateBody(&bd);
    ground->CreateFixture(&shape, 0.0f);
  }

  //part 2

  
  {

    b2BodyDef myBodyDef1;
    myBodyDef1.type = b2_dynamicBody; //this will be a dynamic body
    myBodyDef1.position.Set(-25.0f, 26.0f); //set the starting position
    myBodyDef1.angle = 0;
    b2Body* box1 = m_world->CreateBody(&myBodyDef1);
    b2PolygonShape boxShape1;
    boxShape1.SetAsBox(2.0f,0.25f);
    b2FixtureDef boxFixtureDef1;
    boxFixtureDef1.shape = &boxShape1;
    boxFixtureDef1.density = 3;
    box1->CreateFixture(&boxFixtureDef1);    


    b2BodyDef myBodyDef;
    myBodyDef.type = b2_dynamicBody; //this will be a dynamic body
    myBodyDef.position.Set(-20.0f, 43.25f); //set the starting position
    myBodyDef.angle = 0;
    b2Body* box2 = m_world->CreateBody(&myBodyDef);
    b2PolygonShape boxShape;
    boxShape.SetAsBox(1,1);
    b2FixtureDef boxFixtureDef;
    boxFixtureDef.shape = &boxShape;
    boxFixtureDef.density = 3;
    box2->CreateFixture(&boxFixtureDef);
  // The pulley joint
    b2PulleyJointDef* myjoint1 = new b2PulleyJointDef();

      b2Vec2 worldAnchorGround1(-25.0f, 50.0f); // Anchor point for ground 1 in world axis
      b2Vec2 worldAnchorGround2(-20.0f, 50.0f); // Anchor point for ground 2 in world axis
      float32 ratio = 1.0f; // Define ratio
      myjoint1->Initialize(box1, box2, worldAnchorGround1, worldAnchorGround2, box1->GetWorldCenter(), box2->GetWorldCenter(), ratio);
      m_world->CreateJoint(myjoint1);  

    }

  //part 3
    {
      //The Plank which revolves.
      b2PolygonShape shape;                                                                 
      shape.SetAsBox(20.0f, 0.2f);                            
      b2BodyDef bd,bd3;
      bd.position.Set(-3.0f, 47.0f);                     
      bd.type = b2_dynamicBody;                           
      b2Body* body = m_world->CreateBody(&bd);           
      b2FixtureDef *fd = new b2FixtureDef;                
      fd->density = 1.0f;                                  
      fd->shape = new b2PolygonShape;
      fd->shape = &shape;
      body->CreateFixture(fd);                            

      // Creating a hinge to rotate the platform
      b2PolygonShape shape2;                              
      shape2.SetAsBox(0.2f, 1.0f);                         
      b2BodyDef bd2;
      bd2.position.Set(-3.0f, 45.0f);
      b2Body* body2 = m_world->CreateBody(&bd2);           

      // Revolute joint between the plank and the hinge.    
      b2RevoluteJointDef jointDef;                         
      jointDef.bodyA = body;                               
      jointDef.bodyB = body2;   
      jointDef.localAnchorA.Set(0,0);                     
      jointDef.localAnchorB.Set(0,0);
      jointDef.collideConnected = false;                  
      m_world->CreateJoint(&jointDef);                   

      
    }



    {

        //The Plank which revolves.
      b2PolygonShape shape;                                                                 
      shape.SetAsBox(4.0f, 0.2f);                            
      b2BodyDef bd,bd3;
      bd.position.Set(23.0f, 48.0f);                     
      bd.type = b2_dynamicBody;                           
      b2Body* body = m_world->CreateBody(&bd);           
      b2FixtureDef *fd = new b2FixtureDef;                
      fd->density = 1.0f;                                  
      fd->shape = new b2PolygonShape;
      fd->shape = &shape;
      body->CreateFixture(fd);                            

      // Creating a hinge to rotate the platform
      b2PolygonShape shape2;                              
      shape2.SetAsBox(0.2f, 1.0f);                         
      b2BodyDef bd2;
      bd2.position.Set(23.0f, 46.0f);
      b2Body* body2 = m_world->CreateBody(&bd2);           

      // Revolute joint between the plank and the hinge.    
      b2RevoluteJointDef jointDef;                         
      jointDef.bodyA = body;                               
      jointDef.bodyB = body2;   
      jointDef.localAnchorA.Set(0,0);                     
      jointDef.localAnchorB.Set(0,0);
      jointDef.collideConnected = false;                  
      m_world->CreateJoint(&jointDef);  


          //ball on rotating platform
      b2Body* spherebody;

      b2CircleShape circle;
      circle.m_radius = 0.5;

      b2FixtureDef ballfd;
      ballfd.shape = &circle;
      ballfd.density = 100.0f;
      ballfd.friction = 0.0f;
      ballfd.restitution = 0.5f;



      b2BodyDef ballbd;
      ballbd.type = b2_dynamicBody;
      ballbd.position.Set(23.0f, 49.0f);
      spherebody = m_world->CreateBody(&ballbd);
      spherebody->CreateFixture(&ballfd); 

    }	
  }

      /**
       * A normal member taking no arguments and returning an float32 value representing the zoom.
       * @return The default zoom required, Here taken as 1.25f
       */
  float32 GetDefaultViewZoom() const
  {
    return 1.25f;
  }
  /**
    * A normal member taking no arguments and returning an float32 value representing the zoom.
    * @return The default zoom required, Here taken as 1.25f
    */
  static Test* Create()
  {
    return new Dominos;
  }
};

#endif
