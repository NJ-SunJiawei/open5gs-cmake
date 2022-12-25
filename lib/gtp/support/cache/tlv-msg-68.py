ies = []
ies.append({ "ie_type" : "EBI", "ie_value" : "Linked EPS Bearer ID", "presence" : "M", "instance" : "0", "comment" : ""})
ies.append({ "ie_type" : "PTI", "ie_value" : "Procedure Transaction Id", "presence" : "M", "instance" : "0", "comment" : ""})
ies.append({ "ie_type" : "Flow QoS", "ie_value" : "Flow Quality of Service", "presence" : "C", "instance" : "0", "comment" : "This IE shall be included on the S4/S11 interface if the Requested New QoS/Required QoS is included in the corresponding NAS message (see clause 9.5.10 and clause 9.5.4 in 3GPP TS 24.008 [5]) or the Required traffic flow QoS is included in the corresponding NAS message (see clause 8.3.8 and clause 8.3.10 in 3GPP TS 24.301 [23]). If SGW receives this IE, SGW shall forward it to PGW across S5/S8 interface."})
ies.append({ "ie_type" : "TAD", "ie_value" : "Traffic Aggregate Description", "presence" : "M", "instance" : "0", "comment" : "The TAD consists of the description of the packet filter(s) for a traffic flow aggregate.MME shall include this IE over S11 interface."})
ies.append({ "ie_type" : "RAT Type", "ie_value" : "RAT Type", "presence" : "C", "instance" : "0", "comment" : "This IE shall be included for MS initiated PDP Context modification procedure and Secondary PDP context activation procedure."})
ies.append({ "ie_type" : "Serving Network", "ie_value" : "Serving Network", "presence" : "O", "instance" : "0", "comment" : "This IE may be included in the MS initiated PDP Context modification procedure.See NOTE 3."})
ies.append({ "ie_type" : "ULI", "ie_value" : "User Location Information", "presence" : "O", "instance" : "0", "comment" : "This IE may be included in the MS initiated PDP Context modification procedure.See NOTE 3."})
type_list["EBI"]["max_instance"] = "1"
ies.append({ "ie_type" : "EBI", "ie_value" : "EPS Bearer ID", "presence" : "C", "instance" : "1", "comment" : "This IE indicates the EPS Bearer that needs to be modified. It shall be included for MS initiated PDP Context modification procedure. For EUTRAN this IE shall be present if it is triggered by the NAS Bearer Resource Modification Request message and its value shall be set to the value of the EPS bearer identity for packet filter IE received in that NAS message."})
ies.append({ "ie_type" : "Indication", "ie_value" : "Indication Flags", "presence" : "CO", "instance" : "0", "comment" : "This IE shall be included if any one of the applicable flags is set to 1.Applicable flags:Change Reporting Support Indication: this flag may be set to 1 in the MS initiated PDP Context modification procedure if the SGSN/MME supports location Info Change Reporting and if the SGSN/MMEs operator policy permits reporting of location change to the operator of the PGW with which the session is established.Direct Tunnel Flag: this flag shall be set to 1 on the S4 interface, if Direct Tunnel is used in the MS initiated PDP Context Modification procedure."})
ies.append({ "ie_type" : "F-TEID", "ie_value" : "S4-U SGSN F-TEID", "presence" : "C", "instance" : "0", "comment" : "This IE shall be included on the S4 interface when direct tunnel is not established in the MS initiated PDP Context modification procedure See NOTE 1"})
ies.append({ "ie_type" : "F-TEID", "ie_value" : "S12 RNC F-TEID", "presence" : "C", "instance" : "1", "comment" : "This IE shall be included on the S4 interface when direct tunnel flag is set to 1 in the MS initiated PDP Context modification procedure. See NOTE 1"})
ies.append({ "ie_type" : "PCO", "ie_value" : "Protocol Configuration Options", "presence" : "O", "instance" : "0", "comment" : "If the UE includes the PCO IE, then the MME/SGSN shall copy the content of this IE transparently from the PCO IE included by the UE. If the SGW receives PCO from the MME/SGSN, the SGW shall forward it to the PGW."})
ies.append({ "ie_type" : "Signalling Priority Indication", "ie_value" : "Signalling Priority Indication  ", "presence" : "CO", "instance" : "0", "comment" : "The SGSN/MME shall include this IE on the S4/S11 interface if the UE indicates low access priority during the procedure. The SGW shall forward this IE on the S5/S8 interfaces if received from the MME/SGSN. "})
ies.append({ "ie_type" : "Overload Control Information", "ie_value" : "MME/S4-SGSN's Overload Control Information", "presence" : "O", "instance" : "0", "comment" : "During an overload condition, the MME/S4-SGSN may include this IE on the S11/S4 interface if the overload control feature is supported by the MME/S4-SGSN and is activated for the PLMN to which the PGW belongs (see clause 12.3.11).When present, the MME/S4-SGSN shall provide only one instance of this IE, representing its overload information."})
type_list["Overload Control Information"]["max_instance"] = "1"
ies.append({ "ie_type" : "Overload Control Information", "ie_value" : "SGW's Overload Control Information", "presence" : "O", "instance" : "1", "comment" : "During an overload condition, the SGW may include this IE over the S5/S8 interface if the overload control feature is supported by the SGW and is activated for the PLMN to which the PGW belongs (see clause 12.3.11).When present, the SGW shall provide only one instance of this IE, representing its overload information."})
ies.append({ "ie_type" : "F-Container", "ie_value" : "NBIFOM Container", "presence" : "CO", "instance" : "0", "comment" : "This IE shall be included on the S11/S4 or S2a/S2b interfaces if the MME/S4-SGSN or the TWAN/ePDG receives an NBIFOM Container from the UE as specified in 3GPP TS 24.161 73]. The Container Type shall be set to 4."})
ies.append({ "ie_type" : "ePCO", "ie_value" : "Extended Protocol Configuration Options", "presence" : "O", "instance" : "0", "comment" : "If the UE includes the ePCO IE, then the MME shall copy the content of this IE transparently from the ePCO IE included by the UE. If the SGW receives ePCO from the MME, the SGW shall forward it to the PGW."})
ies.append({ "ie_type" : "F-TEID", "ie_value" : "Sender F-TEID for Control Plane", "presence" : "CO", "instance" : "2", "comment" : "The SGW shall include this IE on the S5/S8 interfaces and set it to the last value sent to the PGW.If the Sender F-TEID for Control Plane is received, the PGW shall only handle the Bearer Resource Command message if the Sender F-TEID for Control Plane in this message is the same as the last Sender F-TEID for Control Plane received on the given interface."})
msg_list[key]["ies"] = ies
