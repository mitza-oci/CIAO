/**
 * @author Johnny Willemsen <jwillemsen@remedy.nl>
 *
 * $Id$
 *
 * Wrapper facade for NDDS.
 */

#ifndef DDS4CCM_GROUPDATAQOSPOLICY_H
#define DDS4CCM_GROUPDATAQOSPOLICY_H

#include "OctetSeq.h"

#if defined (CIAO_DDS4CCM_OPENDDS) && (CIAO_DDS4CCM_OPENDDS==1)
typedef ::DDS::GroupDataQosPolicy DDS_GroupDataQosPolicy;
#endif

#if defined (CIAO_DDS4CCM_NDDS) && (CIAO_DDS4CCM_NDDS==1)

inline void
operator<<= (::DDS::GroupDataQosPolicy &ddsqos, const ::DDS_GroupDataQosPolicy & qos)
{
  ddsqos.value <<= qos.value;
}

inline void
operator<<= (::DDS_GroupDataQosPolicy &ddsqos, const ::DDS::GroupDataQosPolicy & qos)
{
  ddsqos.value <<= qos.value;
}

#endif

#endif /* DDS4CCM_GROUPDATAQOSPOLICY_H */
