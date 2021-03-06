/**
 * @author Johnny Willemsen (jwillemsen@remedy.nl)
 *
 * Wrapper facade for NDDS.
 */

#ifndef DDS4CCM_TIMEBASEDFILTERQOSPOLICY_H
#define DDS4CCM_TIMEBASEDFILTERQOSPOLICY_H

#include "Duration_t.h"
#include "dds4ccm/impl/dds4ccm_conf.h"

inline void
operator<<= (::DDS::TimeBasedFilterQosPolicy &ddsqos, const ::DDS_TimeBasedFilterQosPolicy & qos)
{
  ddsqos.minimum_separation <<= qos.minimum_separation;
}

inline void
operator<<= (::DDS_TimeBasedFilterQosPolicy &ddsqos, const ::DDS::TimeBasedFilterQosPolicy & qos)
{
  ddsqos.minimum_separation <<= qos.minimum_separation;
}

#endif /* DDS4CCM_TIMEBASEDFILTERQOSPOLICY_H */
