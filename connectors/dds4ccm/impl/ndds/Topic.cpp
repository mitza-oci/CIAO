// $Id$

#include "Topic.h"
#include "StatusCondition.h"
#include "InstanceHandle_t.h"
#include "InconsistentTopicStatus.h"
#include "TopicQos.h"
#include "ciao/Logger/Log_Macros.h"

namespace CIAO
{
  namespace DDS4CCM
  {
    namespace RTI
    {
      // Implementation skeleton constructor
      RTI_Topic_i::RTI_Topic_i (void)
        : impl_ (0)
      {
      }

      // Implementation skeleton destructor
      RTI_Topic_i::~RTI_Topic_i (void)
      {
      }

      ::DDS::ReturnCode_t
      RTI_Topic_i::set_qos (const ::DDS::TopicQos &qos)
      {
        ::DDS_TopicQos ddsqos;
        ddsqos <<= qos;
        return this->impl ()->set_qos (ddsqos);
      }

      ::DDS::ReturnCode_t
      RTI_Topic_i::get_qos (::DDS::TopicQos &qos)
      {
        ::DDS_TopicQos ddsqos;
        ::DDS_ReturnCode_t const retval = this->impl ()->get_qos (ddsqos);
        qos <<= ddsqos;
        return retval;
      }

      ::DDS::ReturnCode_t
      RTI_Topic_i::set_listener (::DDS::TopicListener_ptr /*a_listener*/,
                                 ::DDS::StatusMask /*mask*/)
      {
        //RTI_TopicListener_i* rti_impl_list = new RTI_TopicListener_i (a_listener);
        //return this->impl ()->set_listener (rti_impl_list, mask);
        throw CORBA::NO_IMPLEMENT ();
      }

      ::DDS::TopicListener_ptr
      RTI_Topic_i::get_listener (void)
      {
        throw CORBA::NO_IMPLEMENT ();
      }

      ::DDS::ReturnCode_t
      RTI_Topic_i::get_inconsistent_topic_status (::DDS::InconsistentTopicStatus & a_status)
      {
        DDS_InconsistentTopicStatus ddsstatus;
        ddsstatus <<= a_status;
        return this->impl ()->get_inconsistent_topic_status (ddsstatus);
      }

      ::DDS::ReturnCode_t
      RTI_Topic_i::enable (void)
      {
        return this->impl ()->enable ();
      }

      ::DDS::StatusCondition_ptr
      RTI_Topic_i::get_statuscondition (void)
      {
        DDSStatusCondition* sc = this->impl ()->get_statuscondition ();
        ::DDS::StatusCondition_var retval = new RTI_StatusCondition_i (sc);
        return retval._retn ();
      }

      ::DDS::StatusMask
      RTI_Topic_i::get_status_changes (void)
      {
        return this->impl ()->get_status_changes ();
      }

      ::DDS::InstanceHandle_t
      RTI_Topic_i::get_instance_handle (void)
      {
        ::DDS_InstanceHandle_t const rtihandle = this->impl ()->get_instance_handle ();
        ::DDS::InstanceHandle_t handle;
        handle <<= rtihandle;
        return handle;
      }

      char *
      RTI_Topic_i::get_type_name (void)
      {
        return CORBA::string_dup (this->impl ()->get_type_name ());
      }

      char *
      RTI_Topic_i::get_name (void)
      {
        return CORBA::string_dup (this->impl ()->get_name ());
      }

      ::DDS::DomainParticipant_ptr
      RTI_Topic_i::get_participant (void)
      {
        DDSDomainParticipant* p = this->impl ()->get_participant ();
        ::DDS::DomainParticipant_var retval = new RTI_DomainParticipant_i (p);
        return retval._retn ();
      }

      DDSTopic *
      RTI_Topic_i::get_impl (void)
      {
        return this->impl ();
      }

      void
      RTI_Topic_i::set_impl (DDSTopic * dw)
      {
        this->impl_ = dw;
      }

      DDSTopic *
      RTI_Topic_i::impl (void)
      {
        if (!this->impl_)
          {
            throw ::CORBA::BAD_INV_ORDER ();
          }
        return this->impl_;
      }

    }
  }
}
